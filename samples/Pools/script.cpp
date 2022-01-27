/*
	THIS FILE IS A PART OF RDR 2 SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2019
*/

#include "script.h"
#include <string>
#include <vector>
#include <math.h>

#define PLAYER_ID 0		// value for type Player that represents the player

bool isPlayerInCombat()
{
	return PED::IS_PED_IN_COMBAT(PLAYER::PLAYER_PED_ID(), NULL) || PED::IS_PED_IN_MELEE_COMBAT(PLAYER::PLAYER_PED_ID());
}

void update()
{
    if (isPlayerInCombat())
		PLAYER::SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(PLAYER_ID, 0.0f);
	else
		PLAYER::SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(PLAYER_ID, 1.0f);
}

void main()
{

	while (true)
	{
		update();
		WAIT(0);
	}
}

void ScriptMain()
{	
	srand(GetTickCount());
	main();
}
