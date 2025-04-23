#include "CPlayer.h"

CPlayer::CPlayer()
{
	m_tData = {};
	m_cPlayerName[0] = "전사";
	m_cPlayerName[1] = "도적";
	m_cPlayerName[2] = "마법사";
}

CPlayer::CPlayer(DATA _tPlayer)
{
	m_cPlayerName[0] = "전사";
	m_cPlayerName[1] = "도적";
	m_cPlayerName[2] = "마법사";
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
	cout << "이름 : " << m_cPlayerName[m_tData.iName] << endl;
	cout << "체력 : " << m_tData.iHealth << "  공격력 : " << m_tData.iAttackPower << endl;
}

void CPlayer::SelectJob()
{
	system("cls");

	int iInput(0);
	do {
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
		cin >> iInput;
		system("cls");
	} while (iInput < 1 || iInput > 3);

	m_tData = { iInput - 1, 100, 10 };
}
