#include "CPlayer.h"

CPlayer::CPlayer()
{
	m_tData = {};
	m_cPlayerName[0] = "����";
	m_cPlayerName[1] = "����";
	m_cPlayerName[2] = "������";
}

CPlayer::CPlayer(DATA _tPlayer)
{
	m_cPlayerName[0] = "����";
	m_cPlayerName[1] = "����";
	m_cPlayerName[2] = "������";
	m_tData.iName = _tPlayer.iName;
	m_tData.iHealth = _tPlayer.iHealth;
	m_tData.iAttackPower = _tPlayer.iAttackPower;
}


CPlayer::~CPlayer()
{
}

CPlayer* CPlayer::Create()
{
	CPlayer* pCPlayer = new CPlayer();
	return pCPlayer;
}

CPlayer* CPlayer::Create(DATA _tPlayer)
{
	CPlayer* pCPlayer = new CPlayer(_tPlayer);
	return pCPlayer;
}

void CPlayer::Render() const
{
	cout << "=====================================" << endl;
	cout << "�̸� : " << m_cPlayerName[m_tData.iName] << endl;
	cout << "ü�� : " << m_tData.iHealth << "  ���ݷ� : " << m_tData.iAttackPower << endl;
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
