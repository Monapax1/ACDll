#pragma once
#include <Windows.h>
#include "pch.h"
#include <cstdint>
#include  <vector>

struct Entity
{
	//Pointers from game
	BYTE* playerBase = nullptr;
	BYTE* bDead = nullptr;
	float* xCord = nullptr;
	float* yCord = nullptr;
	float* zCord = nullptr;
	int* team = nullptr;
	int* playerNumber = nullptr;
	int* health = nullptr;
	char* name = nullptr;
	


	//DLL only vars used  for checks and aimbot/ESP math
	bool bChecked = false;
	float relativeX = NULL;
	float relativeY = NULL;
	float relativeZ = NULL;
	float distanceFromMe = 99999.0f;


	// just for me

	float* yaw = nullptr;
	float* pitch = nullptr;
	int* Ammo = nullptr;
	int* grenade = nullptr;
};

struct Offsets
{
	DWORD xCord = 0x2C; 
	DWORD yCord = 0x28;
	DWORD zCord = 0x30;
	DWORD team = 0x30C;
	DWORD playerNumber = 0x1C4;
	DWORD bDead = 0x318;
	DWORD name = 0x205;
	DWORD health = 0xEC;
	DWORD currentWeapon = 0x368;
	DWORD armor = 0xF0;
#define EntityList 0x18AC04

	//Just for me
	DWORD yaw = 0x38;
	DWORD pitch = 0x34;
	DWORD Ammo = 0x140;
	DWORD grenade = 0x144;

};

// Generated using ReClass 2016

class Player;
class CurrentWeapon;
class LastWeapon;
class CurrentWeapon;
class N0000018D;
class N00000190;
class N00000193;
class N00000196;
class N00000199;
class N000001A2;
class N000001A5;
class N000001A9;
class N000001AC;
class N000001AF;
class N000001B7;
class N000001BE;
class N000001C1;
class N000001C4;
class N000001C7;
class N000001CC;

class Ent2
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //

	float Head; //0x0004 
	float velocity; //0x0010 
	float velocity2; //0x001C 
	float pos; //0x0028 
	float vViewAngle; //0x0034 
	char pad_0x0040[0x4]; //0x0040
	float N00000015; //0x0044 
	char pad_0x0048[0x4]; //0x0048
	float N00000017; //0x004C 
	float N00000018; //0x0050 
	float N00000019; //0x0054 
	char pad_0x0058[0x4]; //0x0058
	__int32 bJumping; //0x005C 
	char pad_0x0060[0x4]; //0x0060
	__int32 bScoping; //0x0064 
	char pad_0x0068[0x2C]; //0x0068
	float N00000029; //0x0094 
	char pad_0x0098[0x54]; //0x0098
	__int32 Health; //0x00EC 
	__int32 Armor; //0x00F0 
	char pad_0x00F4[0x14]; //0x00F4
	__int32 PistolMag; //0x0108 
	__int32 DmrMag; //0x010C 
	__int32 ShotgunMag; //0x0110 
	__int32 SmgMag; //0x0114 
	__int32 SniperMag; //0x0118 
	__int32 ArMag; //0x011C 
	char pad_0x0120[0xC]; //0x0120
	__int32 PistolAmmo1; //0x012C 
	__int32 DmrAmmo1; //0x0130 
	__int32 ShotgunAmmo1; //0x0134 
	__int32 SmgAmmo1; //0x0138 
	__int32 SniperAmmo1; //0x013C 
	__int32 ArAmmo1; //0x0140 
	__int32 Grenades; //0x0144 
	char pad_0x0148[0x4]; //0x0148
	__int32 KnifeWait; //0x014C 
	__int32 PistolWait; //0x0150 
	__int32 DmrWait; //0x0154 
	__int32 ShotgunWait; //0x0158 
	__int32 SmgWait; //0x015C 
	__int32 SniperWait; //0x0160 
	__int32 ArWait; //0x0164 
	__int32 GrenadeWait; //0x0168 
	char pad_0x016C[0x4]; //0x016C
	__int32 Knifed; //0x0170 
	__int32 PistolFired; //0x0174 
	__int32 DmrFired; //0x0178 
	__int32 ShotgunFired; //0x017C 
	__int32 SmgFired; //0x0180 
	__int32 SniperFired; //0x0184 
	__int32 ArFired; //0x0188 
	__int32 GrenadesThrown; //0x018C 
	char pad_0x0190[0x4C]; //0x0190
	__int32 ScoreboardKills; //0x01DC 
	char pad_0x01E0[0x4]; //0x01E0
	__int32 ScoreboardDeaths; //0x01E4 
	char pad_0x01E8[0x4]; //0x01E8
	__int32 N0000007F; //0x01EC 
	char pad_0x01F0[0x14]; //0x01F0
	unsigned char isAttacking; //0x0204 
	char name[16]; //0x3A5888 
	char pad_0x0215[0xF7]; //0x0215
	__int32 bTeam; //0x030C 
	char pad_0x0310[0x8]; //0x0310
	__int32 bDead; //0x0318 
	char pad_0x031C[0x44]; //0x031C
	LastWeapon* N000000DC; //0x0360 
	CurrentWeapon* N000000DD; //0x0364 
	CurrentWeapon* CurrentWeapon; //0x0368 
	char pad_0x036C[0xD4]; //0x036C

}; //Size=0x0440

class CurrentWeapon
{
public:
	char pad_0x0000[0x4]; //0x0000
	__int32 ID; //0x0004 
	N000001B7* Owner; //0x0008 
	N000001BE* gunInfo; //0x000C 
	N000001C1* MagAmmo; //0x0010 
	N000001C4* Ammo; //0x0014 
	N000001C7* gunwait; //0x0018 
	__int32 shots; //0x001C 
	__int32 reloading; //0x0020 
	char pad_0x0024[0x4]; //0x0024
	__int32 bScoped; //0x0028 
	char pad_0x002C[0x18]; //0x002C

}; //Size=0x0044

class LastWeapon
{
public:
	char pad_0x0000[0x4]; //0x0000
	__int32 ID; //0x0004 
	N000001A2* Owner; //0x0008 
	N000001A5* gunInfo; //0x000C 
	N000001A9* MagAmmo; //0x0010 
	N000001AC* Ammo; //0x0014 
	N000001AF* gunwait; //0x0018 
	__int32 shots; //0x001C 
	__int32 reloading; //0x0020 
	char pad_0x0024[0x20]; //0x0024

}; //Size=0x0044

class CurrentWeapon2
{
public:
	char pad_0x0000[0x4]; //0x0000
	__int32 ID; //0x0004 
	N0000018D* Owner; //0x0008 
	N00000190* guninfo; //0x000C 
	N00000193* MagAmmo; //0x0010 
	N00000196* Ammo; //0x0014 
	N00000199* gunwait; //0x0018 
	__int32 shots; //0x001C 
	__int32 reloading; //0x0020 
	char pad_0x0024[0x20]; //0x0024

}; //Size=0x0044

class N0000018D
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000190
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000193
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000196
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000199
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001A2
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001A5
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001A9
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001AC
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001AF
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001B7
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001BE
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001C1
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001C4
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001C7
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000001CC
{
public:
	char pad_0x0000[0x4]; //0x0000
	__int32 ID; //0x0004 
	char pad_0x0008[0x3C]; //0x0008

}; //Size=0x0044




extern Entity entity[32];
extern Entity myself;
extern Offsets offsets;
