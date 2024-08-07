#include "pch.h"
#include "mainHackLoop.h"

#include "consoleAndInput.h"
#include "globals.h"
#include "harvest.h"
#include "setupHooksandNops.h"
#include "structs.h"


#define numberOfPlayers (gModuleBaseAssaultCube + 0x18AC0C) 

void mainHackLoop()
{
	int currentNumberOfPlayers = *(int*)(numberOfPlayers);
	if (gNumberOfPlayers != currentNumberOfPlayers)
	{
		gNumberOfPlayers = currentNumberOfPlayers;
		//if (!harvestDataTramp.bActive)harvestDataTramp.ToggleTrampSBF();
	}

	//is our harvesting hook finished?
	if (harvestDataTramp.bActive)return;

	if (harvestDataTramp.bActive == 0)
	{
		uintptr_t* entList = (uintptr_t*)(gModuleBaseAssaultCube + 0x18AC04);
	for (int i = 1; i < gNumberOfPlayers; i++)
	{
		uintptr_t ent = *(uintptr_t*)(*entList + (i * 4));
		int* entNumber = (int*)(ent + offsets.playerNumber);
		BYTE* entBase = (BYTE*)(ent);
		MoveDataIntoEnt(entBase, entNumber);
	}
	  //get my info too
	uintptr_t localPlayer = (*(entList - 1));
	int* entNumber = (int*)(localPlayer + offsets.playerNumber);
	BYTE* entBase = (BYTE*)(localPlayer);
	MoveDataIntoEnt(entBase, entNumber);

    }
	for (int i = 0; i < gNumberOfPlayers; i++)
	{
		entity[i].bChecked = false;
	}

	GetInput();
}