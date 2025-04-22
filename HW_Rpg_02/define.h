#pragma once

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}
#define NAME_ARRAY_SIZE 4

typedef struct tagInfo
{
	int		iName;
	int		iHealth;
	int		iAttackPower;


}DATA;
#pragma once
