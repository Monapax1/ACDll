#include "pch.h"
#include "harvest.h"

#include "globals.h"
#include "structs.h"
#include "setupHooksandNops.h"
#include "globals.h"
#include "mainHackLoop.h"



void HarvestData()
{
    int* currentPlayerNumber;
    BYTE* playerBase;
    __asm
    {
        push ebx

        lea ebx, [esi]//PlayerBaseAddress
        mov playerBase, ebx
        lea ebx, [esi + 0x1C4]//PlayerNumber
        mov currentPlayerNumber, ebx

        pop ebx
    }

    MoveDataIntoEnt(playerBase, currentPlayerNumber);

   //is everyone checked?
    for (int i = 0; i < gNumberOfPlayers; i++)
    {
	    if (!entity[i].bChecked)
	    {
            return;
	    }
    }

   // if everyone is checked, setup for next possible check. toggle harvesting
    for (int i = 0; i < gNumberOfPlayers; i++)
    {
        entity[i].bChecked = false;
    }
    //disable hook
    harvestDataTramp.ToggleTrampSBF();
}


void MoveDataIntoEnt(BYTE* playerBase, int* playerNumber)
{

    entity[*playerNumber].playerBase = playerBase;
    entity[*playerNumber].bDead = (playerBase + offsets.bDead);
    entity[*playerNumber].playerNumber = (int*)(playerBase + offsets.playerNumber);
    entity[*playerNumber].team = (int*)(playerBase + offsets.team);
    entity[*playerNumber].xCord = (float*)(playerBase + offsets.xCord);
    entity[*playerNumber].yCord = (float*)(playerBase + offsets.yCord);
    entity[*playerNumber].zCord = (float*)(playerBase + offsets.zCord);
    entity[*playerNumber].name = (char*)(playerBase + offsets.name);
    entity[*playerNumber].health = (int*)(playerBase + offsets.health);
    entity[*playerNumber].Ammo = (int*)(playerBase + offsets.Ammo);
    entity[*playerNumber].bChecked = true;
    entity[*playerNumber].yaw = (float*)(playerBase + offsets.yaw);
    entity[*playerNumber].pitch = (float*)(playerBase + offsets.pitch);
    entity[*playerNumber].grenade = (int*)(playerBase + offsets.grenade);
  
    //I am playernumber 0
    if (*playerNumber == 0)
    {
        myself = entity[0];
       myself.pitch = (float*)(playerBase + offsets.pitch);
        myself.yaw = (float*)(playerBase + offsets.yaw);
        myself.Ammo = (int*)(playerBase + offsets.Ammo);

    }
}