#include "pch.h"
#include "mem.h"

Hook::Hook(BYTE* hookPosition, BYTE* desiredFunction, int lengthOfHook)
{
	// Use arguments to define our Hook's variables
	this->hookPosition = hookPosition;
	this->desiredFunction = desiredFunction;
	this->lengthOfHook = lengthOfHook;

	// Copy stolen bytes
	memcpy(stolenBytes, hookPosition, lengthOfHook);

	// Allocate room for our trampoline
	trampoline = (BYTE*)VirtualAlloc(nullptr, lengthOfHook + sizeof(preserveStack) + 5 + sizeof(releaseStack), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	// Setup trampoline
	hookToTrampJump = (DWORD)(trampoline - hookPosition) - 5;
	returnJump = (DWORD)(hookPosition + lengthOfHook) - (DWORD)(trampoline + lengthOfHook + sizeof(preserveStack) + 5 + sizeof(releaseStack)) - 5;

	// Setup detour jumps
	hookToDetourJump = (DWORD)(desiredFunction - hookPosition) - 5;
	returnJumpDetour = (DWORD)(hookPosition + lengthOfHook);
}

Hook::Hook()
{
	// Do nothing
}

void Hook::ToggleTrampSBF()
{
	// Toggle hook state
	bActive = !bActive;

	if (bActive)
	{
		// Make it so that we can execute/read/write bytes at hook location
		DWORD oldProtection;
		VirtualProtect(hookPosition, lengthOfHook, PAGE_EXECUTE_READWRITE, &oldProtection);

		// Is the trampoline already built?
		if (!bTrampBuild)
		{
			// In our trampoline, jump to our space in the DLL for the specified function
			trampToFuncCall = (DWORD)desiredFunction - (DWORD)(trampoline + lengthOfHook + sizeof(preserveStack)) - 5;

			// Stolen bytes placed, stack preserved, call our desired function
			memcpy(trampoline, hookPosition, lengthOfHook);
			memcpy(trampoline + lengthOfHook, preserveStack, sizeof(preserveStack));
			*(BYTE*)(trampoline + lengthOfHook + sizeof(preserveStack)) = 0xE8; // CALL instruction
			*(DWORD*)(trampoline + lengthOfHook + sizeof(preserveStack) + 1) = trampToFuncCall;

			// Release stack, jump back to after hook
			memcpy(trampoline + lengthOfHook + sizeof(preserveStack) + 5, releaseStack, sizeof(releaseStack));
			*(BYTE*)(trampoline + lengthOfHook + sizeof(preserveStack) + 5 + sizeof(releaseStack)) = 0xE9; // JMP instruction
			*(DWORD*)(trampoline + lengthOfHook + sizeof(preserveStack) + 5 + sizeof(releaseStack) + 1) = returnJump;

			// Trampoline is built
			bTrampBuild = true;
		}

		// Set hook inside the game's memory
		memset(hookPosition, 0x90, lengthOfHook); // NOP instructions
		*(BYTE*)hookPosition = 0xE9; // JMP instruction
		*(DWORD*)(hookPosition + 1) = hookToTrampJump;

		// Restore protection
		VirtualProtect(hookPosition, lengthOfHook, oldProtection, nullptr);
	}
	else
	{
		// Restore original bytes
		DWORD oldProtection;
		VirtualProtect(hookPosition, lengthOfHook, PAGE_EXECUTE_READWRITE, &oldProtection);
		memcpy(hookPosition, stolenBytes, lengthOfHook);
		VirtualProtect(hookPosition, lengthOfHook, oldProtection, nullptr);
	}
}

void Hook::ToggleDetour()
{
	// Toggle hook state
	bActive = !bActive;

	DWORD oldProtection;
	VirtualProtect(hookPosition, lengthOfHook, PAGE_EXECUTE_READWRITE, &oldProtection);

	if (bActive)
	{
		// Set detour hook inside the game's memory
		memset(hookPosition, 0x90, lengthOfHook); // NOP instructions
		*(BYTE*)hookPosition = 0xE9; // JMP instruction
		*(DWORD*)(hookPosition + 1) = hookToDetourJump;
	}
	else
	{
		// Restore original bytes
		memcpy(hookPosition, stolenBytes, lengthOfHook);
	}

	// Restore protections
	VirtualProtect(hookPosition, lengthOfHook, oldProtection, nullptr);
}

NOP::NOP(BYTE* nopPosition, int length)
{
	this->nopPosition = nopPosition;
	this->length = length;
	memcpy(stolenBytes, nopPosition, length);
}

NOP::NOP()
{
	// Do nothing
}

void NOP::ToggleNOP()
{
	// Toggle NOP state
	bActive = !bActive;

	DWORD oldProtection;
	VirtualProtect(nopPosition, length, PAGE_EXECUTE_READWRITE, &oldProtection);

	if (bActive)
	{
		memset(nopPosition, 0x90, length); // NOP instructions
	}
	else
	{
		// Restore original bytes
		memcpy(nopPosition, stolenBytes, length);
	}

	// Restore protections
	VirtualProtect(nopPosition, length, oldProtection, &oldProtection);
}
