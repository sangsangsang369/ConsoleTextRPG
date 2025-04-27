#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::CMonster(DATA _tObject)
	:CObject(_tObject)
{	
}

CMonster::CMonster(int _iName, int _iHealth, int _iAttackPower)
	:CObject(_iName, _iHealth, _iAttackPower)
{	
}

CMonster::~CMonster()
{
}

CObject* CMonster::Create()
{
	CObject* pCMonster = new CMonster();
	return pCMonster;
}

CObject* CMonster::Create(DATA _tObject)
{
	CObject* pCMonster = new CMonster(_tObject);
	return pCMonster;
}

CObject* CMonster::Create(int _iName, int _iHealth, int _iAttackPower)
{
	CObject* pCMonster = new CMonster(_iName, _iHealth, _iAttackPower);
	return pCMonster;
}

void CMonster::Render() const
{
	g_RenderLine(SCREEN_W);
	cout << "�̸� : " << g_cMonsterNameArray[m_tData.iName] << endl;
	cout << "ü�� : " << m_tData.iHealth << "  ���ݷ� : " << m_tData.iAttackPower << endl;
}



