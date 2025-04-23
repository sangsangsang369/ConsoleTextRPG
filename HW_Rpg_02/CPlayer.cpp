#include "CPlayer.h"

CPlayer::CPlayer()
{
	m_tData = {};
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		m_tInventory[i] = g_tItemArray[i];
	}
	m_iMoney = 0;
}

CPlayer::CPlayer(DATA _tPlayer, ITEM* _pInventory, int _iMoney)
{
	m_tData.iName = _tPlayer.iName;
	m_tData.iHealth = _tPlayer.iHealth;
	m_tData.iAttackPower = _tPlayer.iAttackPower;
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		m_tInventory[i] = _pInventory[i];
	}
	m_iMoney = _iMoney;
}


CPlayer::~CPlayer()
{
}

CPlayer* CPlayer::Create()
{
	CPlayer* pCPlayer = new CPlayer();
	return pCPlayer;
}

CPlayer* CPlayer::Create(DATA _tPlayer, ITEM* _pInventory, int _iMoney)
{
	CPlayer* pCPlayer = new CPlayer(_tPlayer, _pInventory, _iMoney);
	return pCPlayer;
}

void CPlayer::Render() const
{
	cout << "=====================================" << endl;
	cout << "�̸� : " << g_cPlayerNameArray[m_tData.iName] << endl;
	cout << "ü�� : " << m_tData.iHealth << "  ���ݷ� : " << m_tData.iAttackPower << endl;
	cout << "ĳ�� : " << m_iMoney << endl;
}

void CPlayer::RenderInventory() const
{
	cout << "=====================================" << endl;
	cout << "�κ��丮" << endl;
	cout << "=====================================" << endl;
	cout << "ĳ�� : " << m_iMoney << endl;
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		cout << "=====================================" << endl;
		cout << g_cItemNameArray[i] << endl;
		cout << "���� ���� : " << m_tInventory[i].iNumInInventory << endl;
	}
}

void CPlayer::SelectJob()
{
	system("cls");

	int iInput(0);
	do {
		cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";
		cin >> iInput;
		system("cls");
	} while (iInput < 1 || iInput > 3);

	m_tData = { iInput - 1, 100, 10 };
}
