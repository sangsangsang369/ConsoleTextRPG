#include "CObject.h"

CObject::CObject()
{
	m_tData = {};
}

void CObject::Render(int _iType) const
{
	switch (_iType)
	{
	case(PLAYER):
		cout << "=====================================" << endl;
		cout << "이름 : " << g_cPlayerNameArray[m_tData.iName] << endl;
		cout << "체력 : " << m_tData.iHealth << "  공격력 : " << m_tData.iAttackPower << endl;
		//cout << "캐시 : " << m_iMoney << endl;
		break;
	case(MONSTER):
		cout << "=====================================" << endl;
		cout << "이름 : " << g_cMonsterNameArray[m_tData.iName] << endl;
		cout << "체력 : " << m_tData.iHealth << "  공격력 : " << m_tData.iAttackPower << endl;
		break;
	default:
		break;
	}
}
