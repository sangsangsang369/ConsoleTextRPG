#include "CMainGame.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pField = nullptr;
	m_pSave = nullptr;
	m_bFirstCheck = false;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	if (!m_pSave)
	{
		m_pSave = new CSave();
	}
	DATA* pSaveExist = m_pSave->CheckSaveFile();

	if (pSaveExist != nullptr)
	{
		if (!m_pPlayer)
		{
			m_pPlayer = new CPlayer(pSaveExist[0]);
		}

		if (!m_pField)
		{
			m_pField = new CField(m_pSave);
		}
		m_pField->Set_pPlayerCopy(m_pPlayer);
		m_pField->Set_pMonsterFromSaveFile();
	}
	else
	{
		if (!m_pPlayer)
		{
			m_pPlayer = new CPlayer();
		}	
		m_pPlayer->SelectJob();

		if (!m_pField)
		{
			m_pField = new CField(m_pSave);
		}	
		m_pField->Set_pPlayerCopy(m_pPlayer);
	}
}

void CMainGame::Update()
{
	int		iInput(0);

	while (true)
	{
		system("cls");
		if (m_pSave && !m_bFirstCheck)
		{
			m_bFirstCheck = true;
			if (m_pField)
				m_pField->Update();
		}
		else
		{
			m_pPlayer->Render();

			cout << "1. 사냥터 2. 종료 : ";
			cin >> iInput;

			switch (iInput)
			{
			case(1):
				if (m_pField)
					m_pField->Update();
				break;
			case(2):
				exit(0);
				break;
			default:
				break;
			}
		}
	}
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pSave);
}




