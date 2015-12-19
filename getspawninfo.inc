/*

	About: get spawn info function
	Author: ziggi

*/

#if !defined _samp_included
	#error "Please include a_samp or a_npc before getspawninfo"
#endif

#if defined _getspawninfo_included
	#endinput
#endif

#define _getspawninfo_included
#pragma library getspawninfo

/*
	Vars
*/

static
	gInfoTeam[MAX_PLAYERS char],
	gInfoSkin[MAX_PLAYERS],
	Float:gInfoPosX[MAX_PLAYERS],
	Float:gInfoPosY[MAX_PLAYERS],
	Float:gInfoPosZ[MAX_PLAYERS],
	Float:gInfoRotation[MAX_PLAYERS],
	gInfoWeapon1[MAX_PLAYERS char],
	gInfoWeapon1_Ammo[MAX_PLAYERS],
	gInfoWeapon2[MAX_PLAYERS char],
	gInfoWeapon2_Ammo[MAX_PLAYERS],
	gInfoWeapon3[MAX_PLAYERS char],
	gInfoWeapon3_Ammo[MAX_PLAYERS];

/*
	Functions
*/

stock spawninfo_SetSpawnInfo(playerid, team, skin,
                             Float:x, Float:y, Float:z, Float:rotation,
                             weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	gInfoTeam{playerid} = team;
	gInfoSkin[playerid] = skin;
	gInfoPosX[playerid] = x;
	gInfoPosY[playerid] = y;
	gInfoPosZ[playerid] = z;
	gInfoRotation[playerid] = rotation;
	gInfoWeapon1{playerid} = weapon1;
	gInfoWeapon1_Ammo[playerid] = weapon1_ammo;
	gInfoWeapon2{playerid} = weapon2;
	gInfoWeapon2_Ammo[playerid] = weapon2_ammo;
	gInfoWeapon3{playerid} = weapon3;
	gInfoWeapon3_Ammo[playerid] = weapon3_ammo;

	return SetSpawnInfo(playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}
#if defined _ALS_SetSpawnInfo
	#undef SetSpawnInfo
#else
	#define _ALS_SetSpawnInfo
#endif
 
#define SetSpawnInfo spawninfo_SetSpawnInfo

stock GetSpawnInfo(playerid, &team = NO_TEAM, &skin = 0,
                   &Float:x = 0.0, &Float:y = 0.0, &Float:z = 0.0, &Float:rotation = 0.0,
                   &weapon1 = 0, &weapon1_ammo = 0, &weapon2 = 0, &weapon2_ammo = 0, &weapon3 = 0, &weapon3_ammo = 0)
{
	team = gInfoTeam{playerid};
	skin = gInfoSkin[playerid];
	x = gInfoPosX[playerid];
	y = gInfoPosY[playerid];
	z = gInfoPosZ[playerid];
	rotation = gInfoRotation[playerid];
	weapon1 = gInfoWeapon1{playerid};
	weapon1_ammo = gInfoWeapon1_Ammo[playerid];
	weapon2 = gInfoWeapon2{playerid};
	weapon2_ammo = gInfoWeapon2_Ammo[playerid];
	weapon3 = gInfoWeapon3{playerid};
	weapon3_ammo = gInfoWeapon3_Ammo[playerid];
}
