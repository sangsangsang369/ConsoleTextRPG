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
		g_RenderLine(SCREEN_W);
		cout << "�̸� : " << g_cPlayerNameArray[m_tData.iName] << endl;
		cout << "ü�� : " << m_tData.iHealth << "  ���ݷ� : " << m_tData.iAttackPower << endl;
		//cout << "ĳ�� : " << m_iMoney << endl;
		break;
	case(MONSTER):
		g_RenderLine(SCREEN_W);
		cout << "�̸� : " << g_cMonsterNameArray[m_tData.iName] << endl;
		cout << "ü�� : " << m_tData.iHealth << "  ���ݷ� : " << m_tData.iAttackPower << endl;
		break;
	default:
		break;
	}
}
