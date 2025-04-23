#pragma once
#include "pch.h"
#include "define.h"

class CMonster
{
private:
	DATA m_tData;
	const char* m_cMonsterName[NAME_ARRAY_SIZE];

public:
	CMonster();
	CMonster(DATA _tMonster);
	CMonster(int _iName, int _iHealth, int _iAttackPower);
	~CMonster();

public:
	static CMonster* Create();
	static CMonster* Create(DATA _tMonster);
	static CMonster* Create(int _iName, int _iHealth, int _iAttackPower);

public:
	DATA Get_m_tData() const { return m_tData; }
	void GetDamage(int _iAttack) { m_tData.iHealth -= _iAttack; }

public:
	void Render() const;
};

