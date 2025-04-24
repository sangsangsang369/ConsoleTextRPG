#include "CMainGame.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pField = nullptr;
	m_pShop = nullptr;
	m_pSave = nullptr;
	m_bFirstCheck = false;
	m_tDataArray = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	if (!m_pSave)
	{
		m_pSave = CSave::Create();
	}
	m_tDataArray = m_pSave->CheckSaveFile();

	if (m_tDataArray != nullptr)
	{
		if (!m_pPlayer)
		{
			m_pPlayer = CPlayer::Create(m_tDataArray[0], m_pSave->Get_m_tInventory(), m_pSave->Get_m_iSavedMoney());
		}

		if (!m_pField)
		{
			m_pField = CField::Create(m_pSave);
		}
		m_pField->Set_pPlayerCopy(m_pPlayer);
		m_pField->Set_pMonsterFromSaveFile();

		if (!m_pShop)
		{
			m_pShop = CShop::Create();
		}
		m_pShop->Set_pPlayerCopy(m_pPlayer);
	}
	else
	{
		if (!m_pPlayer)
		{
			m_pPlayer = CPlayer::Create();
		}	
		m_pPlayer->SelectJob();

		if (!m_pField)
		{
			m_pField = CField::Create(m_pSave);
		}	
		m_pField->Set_pPlayerCopy(m_pPlayer);

		if (!m_pShop)
		{
			m_pShop = CShop::Create();
		}
		m_pShop->Set_pPlayerCopy(m_pPlayer);
	}
}

void CMainGame::Update()
{
	int		iInput(0);

	while (true)
	{
		system("cls");
		if (m_tDataArray && !m_bFirstCheck)
		{
			m_bFirstCheck = true;
			if (m_pField)
				m_pField->Update();
		}
		else
		{
			m_pPlayer->Render(PLAYER);

			cout << "1. 사냥터 2. 상점 3. 종료 : ";
			cin >> iInput;

			switch (iInput)
			{
			case(1):
				if (m_pField)
					m_pField->Update();
				break;
			case(2):
				if (m_pShop)
					m_pShop->Update();
				break;
			case(3):
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
	SAFE_DELETE(m_pShop);
	SAFE_DELETE(m_pSave);
}




