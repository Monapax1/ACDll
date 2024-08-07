#include "pch.h"
#include "consoleAndInput.h"
#include <iostream>
#include "setupHooksandNops.h"
#include "structs.h"
#include "mainHackLoop.h"
#include "globals.h"


bool bBreakHackThreadWhileLoop = false;

void GetInput()
{
	//unInject
	if (GetAsyncKeyState(VK_END) & 1)
	{
		BreakHackLoop();
	}
	//Unlimited Ammo
	if (GetAsyncKeyState(VK_NUMPAD0) & 1)
	{
		infAmmoNOP.ToggleNOP();
		PrintConsole();
	}
	//

	if (GetAsyncKeyState(VK_NUMPAD1) & 1)
	{
		godModeNOP.ToggleNOP();
		PrintConsole();
	}
	//InfNades
	if (GetAsyncKeyState(VK_NUMPAD2) & 1)
	{
		infGrenadeNOP.ToggleNOP();
		PrintConsole();
	}
	//ADD GETASYNCKEYSTATE FOR NOP HERE


}

void PrintConsole() // Console edit here
{
	SetConsoleTitle(L"21c Assault Cube Cheeto");
	//erase previous info
	system("CLS");
	std::cout << "Press NUMPAD0 for infAmmoNOP" << std::endl;
	std::cout << "Press NUMPAD2 for Inf Grenades/ Have at least 1" << std::endl;
	std::cout << "Press NUMPAD1 for GodMode" << std::endl;
	//	std::cout << "Press NUMPAD4 for GodMode" << std::endl;
	//	std::cout << "wad" << std::endl;
	//	std::cout << "Press NUMPAD6 for GodMode" << std::endl;
	//	std::cout << "Press NUMPAD7 for GodMode" << std::endl;
	std::cout << "Press END for unInject" << std::endl;
	std::cout << "====================================================" << std::endl;
	std::cout << (infAmmoNOP.bActive ? "On\n" : "Off\n"); 
	std::cout << (infGrenadeNOP.bActive ? "On\n" : "Off\n");
	std::cout << (godModeNOP.bActive ? "On\n" : "Off\n");
	


}
void BreakHackLoop()
{
	//Make sure everything is deactivated
	if (infAmmoNOP.bActive)infAmmoNOP.ToggleNOP();
	if (godModeNOP.bActive)godModeNOP.ToggleNOP();
	if (infGrenadeNOP.bActive)infGrenadeNOP.ToggleNOP();
	

	//Toggle off main hook loop hook, then break while loop inside the HackThread()
	mainHackLoopTramp.ToggleTrampSBF();
	bBreakHackThreadWhileLoop = true;
}
void ToggleConsole()
{
	static bool bActive = false;
	static FILE* f;
	bActive = !bActive;
	if (bActive)
	{
		AllocConsole();
		freopen_s(&f, "CONOUT$", "w", stdout);
	}
	if (!bActive)
	{
		fclose(f);
		FreeConsole();
	}
}
