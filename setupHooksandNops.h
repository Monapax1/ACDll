#pragma once
#include "mem.h"
//EXTERN ALL HOOKS AND NOPS HERE

extern Hook mainHackLoopTramp;
extern NOP infAmmoNOP;
extern NOP godModeNOP;
extern NOP infGrenadeNOP;
extern Hook harvestDataTramp;

void setupHooksandNops();