#include "pch.h"
#include "harvest.h"
#include "structs.h"
#include "setupHooksandNops.h"
#include "globals.h"
#include "consoleAndInput.h"
#include "mainHackLoop.h"
#include "mem.h"

// Declare all hooks and NOPs
// ADD ALL NEW HOOKS AND NOPS HERE
Hook mainHackLoopTramp;
NOP infAmmoNOP;
NOP godModeNOP;
NOP infGrenadeNOP;
Hook harvestDataTramp;

void setupHooksandNops()
{
	// Ensure we have our module bases
	BYTE* moduleBaseAssaultCube = (BYTE*)GetModuleHandle(L"ac_client.exe");
	BYTE* moduleBaseOpenGL = (BYTE*)GetModuleHandle(L"opengl32.dll");

	// Main hook loop
	BYTE* mainHackLoopDst = moduleBaseOpenGL + 0x47AD3;
	Hook mainHackLoopTrampTemp(mainHackLoopDst, (BYTE*)mainHackLoop, 5);
	mainHackLoopTramp = mainHackLoopTrampTemp;


	// Infinite ammo NOP
	BYTE* infAmmoNOPDst = moduleBaseAssaultCube + 0xC73EF;
	NOP infAmmoNOPTemp = NOP(infAmmoNOPDst, 2);
	infAmmoNOP = infAmmoNOPTemp;

	// GodMode NOP
	BYTE* godModeNOPDst = moduleBaseAssaultCube + 0x1C223;
	NOP godModeNOPTemp = NOP(godModeNOPDst, 3);
	godModeNOP = godModeNOPTemp;

	// Infinite grenades NOP
	BYTE* infGrenadeNopDst = moduleBaseAssaultCube + 0xC7E5D;
	NOP infGrenadeNOPTemp = NOP(infGrenadeNopDst, 2);
	infGrenadeNOP = infGrenadeNOPTemp;

}
