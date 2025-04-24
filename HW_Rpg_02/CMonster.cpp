#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::CMonster(DATA _tMonster)
{
	m_tData.iName = _tMonster.iName;
	m_tData.iHealth = _tMonster.iHealth;
	m_tData.iAttackPower = _tMonster.iAttackPower;
}

CMonster::CMonster(int _iName, int _iHealth, int _iAttackPower)
{
	m_tData.iName = _iName;
	m_tData.iHealth = _iHealth;
	m_tData.iAttackPower = _iAttackPower;
}

CMonster::~CMonster()
{
}

CMonster* CMonster::Create()
{
	CMonster* pCMonster = new CMonster();
	return pCMonster;
}

CMonster* CMonster::Create(DATA _tMonster)
{
	CMonster* pCMonster = new CMonster(_tMonster);
	return pCMonster;
}

CMonster* CMonster::Create(int _iName, int _iHealth, int _iAttackPower)
{
	CMonster* pCMonster = new CMonster(_iName, _iHealth, _iAttackPower);
	return pCMonster;
}



