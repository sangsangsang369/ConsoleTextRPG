#pragma once

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}
#define NAME_ARRAY_SIZE 4
#define ALL_ITEM_TYPE_NUM 2
#define MONEY_WEIGHT 10


typedef struct tagInfo
{
	int		iName;
	int		iHealth;
	int		iAttackPower;
}DATA;

typedef struct tagItem
{
	int		iName;
	int		iCost;
	int		iWeight;
	int		iNumInInventory;
}ITEM;

static const char* g_cPlayerNameArray[NAME_ARRAY_SIZE] = {
	"����",
	"������",
	"����"
};

static const char* g_cMonsterNameArray[NAME_ARRAY_SIZE] = {
	"�ʱ�",
	"�߱�",
	"���"
};

static const char* g_cItemNameArray[ALL_ITEM_TYPE_NUM] = {
	"����",
	"������"
};

static ITEM g_tItemArray[ALL_ITEM_TYPE_NUM] = {
	{0,30,20,0},
	{1,40,20,0}
};

enum ITEM_TYPE {
	POTION = 1,
	AMPLIFIER
};
