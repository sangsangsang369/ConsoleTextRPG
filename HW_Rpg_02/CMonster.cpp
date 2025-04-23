#include "CMonster.h"

CMonster::CMonster()
{
	m_tData = {};
	m_cMonsterName[0] = g_cMonsterNameArray[0];
	m_cMonsterName[1] = g_cMonsterNameArray[1];
	m_cMonsterName[2] = g_cMonsterNameArray[2];
}

CMonster::CMonster(DATA _tMonster)
{
	m_cMonsterName[0] = g_cMonsterNameArray[0];
	m_cMonsterName[1] = g_cMonsterNameArray[1];
	m_cMonsterName[2] = g_cMonsterNameArray[2];
	m_tData.iName = _tMonster.iName;
	m_tData.iHealth = _tMonster.iHealth;
	m_tData.iAttackPower = _tMonster.iAttackPower;
}

CMonster::CMonster(int _iName, int _iHealth, int _iAttackPower)
{
	m_cMonsterName[0] = g_cMonsterNameArray[0];
	m_cMonsterName[1] = g_cMonsterNameArray[1];
	m_cMonsterName[2] = g_cMonsterNameArray[2];
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

void CMonster::Render() const
{
	cout << "=====================================" << endl;
	cout << "이름 : " << m_cMonsterName[m_tData.iName] << endl;
	cout << "체력 : " << m_tData.iHealth << "  공격력 : " << m_tData.iAttackPower << endl;
}


