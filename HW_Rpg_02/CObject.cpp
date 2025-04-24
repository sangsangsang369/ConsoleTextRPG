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
		cout << "�̸� : " << g_cPlayerNameArray[m_tData.iName] << endl;
		cout << "ü�� : " << m_tData.iHealth << "  ���ݷ� : " << m_tData.iAttackPower << endl;
		//cout << "ĳ�� : " << m_iMoney << endl;
		break;
	case(MONSTER):
		cout << "=====================================" << endl;
		cout << "�̸� : " << g_cMonsterNameArray[m_tData.iName] << endl;
		cout << "ü�� : " << m_tData.iHealth << "  ���ݷ� : " << m_tData.iAttackPower << endl;
		break;
	default:
		break;
	}
}
