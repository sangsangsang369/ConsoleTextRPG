#include "CPlayer.h"

CPlayer::CPlayer()
{
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		m_tInventory[i] = g_tItemArray[i];
	}
	m_iMoney = 0;
}

CPlayer::CPlayer(DATA _tObject, ITEM* _pInventory, int _iMoney)
	:CObject(_tObject, _pInventory, _iMoney)
{
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		m_tInventory[i] = _pInventory[i];
	}
	m_iMoney = _iMoney;
}


CPlayer::~CPlayer()
{
}

CObject* CPlayer::Create()
{
	CObject* pCPlayer = new CPlayer();
	return pCPlayer;
}

CObject* CPlayer::Create(DATA _tObject, ITEM* _pInventory, int _iMoney)
{
	CObject* pCPlayer = new CPlayer(_tObject, _pInventory, _iMoney);
	return pCPlayer;
}

void CPlayer::Render() const
{
	g_RenderLine(SCREEN_W);
	cout << "�̸� : " << g_cPlayerNameArray[m_tData.iName] << endl;
	cout << "ü�� : " << m_tData.iHealth << "  ���ݷ� : " << m_tData.iAttackPower << endl;
	cout << "ĳ�� : " << m_iMoney << endl;
}

void CPlayer::RenderInventory() const
{
	g_RenderLine(SCREEN_W);
	cout << "�κ��丮" << endl;
	g_RenderLine(SCREEN_W);
	cout << "ĳ�� : " << m_iMoney << endl;
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		g_RenderLine(SCREEN_W);
		cout << i+1 << ". " << g_cItemNameArray[i] << endl;
		cout << "���� ���� : " << m_tInventory[i].iNumInInventory << endl;
	}
}

void CPlayer::SelectJob()
{
	system("cls");

	int iInput(0);
	g_RenderLine(SCREEN_W);
	for (int i = 0; i < ICON_H; i++)
	{
		cout << "   " << KnifeIconGraphic[i] << "    " << HatIconGraphic[i] << "    " << ThiefIconGraphic[i] << endl;
	}
	g_RenderLine(SCREEN_W);
	do {
		cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";
		cin >> iInput;
		system("cls");
	} while (iInput < 1 || iInput > 3);

	m_tData = { iInput - 1, 100, 10 };
}
