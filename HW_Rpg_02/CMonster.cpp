#include "CMonster.h"

CMonster::CMonster()
{
	m_tData = {};
	m_cMonsterName[0] = "�ʱ�";
	m_cMonsterName[1] = "�߱�";
	m_cMonsterName[2] = "���";
}

CMonster::CMonster(DATA _tMonster)
{
	m_cMonsterName[0] = "�ʱ�";
	m_cMonsterName[1] = "�߱�";
	m_cMonsterName[2] = "���";
	m_tData.iName = _tMonster.iName;
	m_tData.iHealth = _tMonster.iHealth;
	m_tData.iAttackPower = _tMonster.iAttackPower;
}

CMonster::CMonster(int _iName, int _iHealth, int _iAttackPower)
{
	m_cMonsterName[0] = "�ʱ�";
	m_cMonsterName[1] = "�߱�";
	m_cMonsterName[2] = "���";
	m_tData.iName = _iName;
	m_tData.iHealth = _iHealth;
	m_tData.iAttackPower = _iAttackPower;
}

CMonster::~CMonster()
{
}

void CMonster::Render() const
{
	cout << "=====================================" << endl;
	cout << "�̸� : " << m_cMonsterName[m_tData.iName] << endl;
	cout << "ü�� : " << m_tData.iHealth << "  ���ݷ� : " << m_tData.iAttackPower << endl;
}


