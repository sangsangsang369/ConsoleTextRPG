#pragma once
#include "CObject.h"

class CMonster : public CObject
{
private:
	//const char* m_cMonsterName[NAME_ARRAY_SIZE];

public:
	CMonster();
	CMonster(DATA _tMonster);
	CMonster(int _iName, int _iHealth, int _iAttackPower);
	~CMonster();

public:
	static CMonster* Create();
	static CMonster* Create(DATA _tMonster);
	static CMonster* Create(int _iName, int _iHealth, int _iAttackPower);
};

