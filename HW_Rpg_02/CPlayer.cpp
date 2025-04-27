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
	cout << "이름 : " << g_cPlayerNameArray[m_tData.iName] << endl;
	cout << "체력 : " << m_tData.iHealth << "  공격력 : " << m_tData.iAttackPower << endl;
	cout << "캐시 : " << m_iMoney << endl;
}

void CPlayer::RenderInventory() const
{
	g_RenderLine(SCREEN_W);
	cout << "인벤토리" << endl;
	g_RenderLine(SCREEN_W);
	cout << "캐시 : " << m_iMoney << endl;
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		g_RenderLine(SCREEN_W);
		cout << i+1 << ". " << g_cItemNameArray[i] << endl;
		cout << "소지 갯수 : " << m_tInventory[i].iNumInInventory << endl;
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
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
		cin >> iInput;
		system("cls");
	} while (iInput < 1 || iInput > 3);

	m_tData = { iInput - 1, 100, 10 };
}
