#include "CField.h"

CField::CField()
{
	m_pPlayerCopy = nullptr;
	m_pMonster = nullptr;
	m_pSaveCopy = nullptr;
}

CField::CField(CSave* _pSave)
{
	m_pPlayerCopy = nullptr;
	m_pMonster = nullptr;
	m_pSaveCopy = _pSave;
}

CField::~CField()
{
	Release();
}

void CField::Set_pMonsterFromSaveFile()
{
	if (m_pSaveCopy)
	{
		m_pMonster = new CMonster(m_pSaveCopy->Get_tDataArray()[1]);
	}
}

void CField::Initialize()
{
}

void CField::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		if (!m_pMonster)
		{
			do {
				m_pPlayerCopy->Render();
				cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
				cin >> iInput;
				system("cls");
			} while (iInput < 1 || iInput > 4);

			switch (iInput)
			{
			case(1):
			case(2):
			case(3):
				m_pMonster = new CMonster(iInput - 1, 30 * iInput, 3 * iInput);
				break;
			case(4):
				return;
				break;

			default:
				break;
			}
		}
		
		int iResult = Fight();
		switch (iResult)
		{
		case(0):
			m_pPlayerCopy->SetHealth(100);
			SAFE_DELETE(m_pMonster);
		case(1):
			SAFE_DELETE(m_pMonster);
		case(2):
			SAFE_DELETE(m_pMonster);
		default:
			break;
		}
	}
}

void CField::Release()
{
	SAFE_DELETE(m_pPlayerCopy);
	SAFE_DELETE(m_pMonster);
	SAFE_DELETE(m_pSaveCopy);
}

int CField::Fight()
{
	while (true)
	{
		system("cls");

		int iInput(0);
		do {
			m_pPlayerCopy->Render();
			m_pMonster->Render();
			cout << "1. 공격 2. 도망 3. 저장: ";
			cin >> iInput;
		} while (iInput < 1 || iInput > 3);

		switch (iInput)
		{
		case(1):
			m_pPlayerCopy->GetDamage(m_pMonster->GetData().iAttackPower);
			m_pMonster->GetDamage(m_pPlayerCopy->GetData().iAttackPower);

			if (m_pPlayerCopy->GetData().iHealth <= 0)
			{
				cout << "사망" << endl;
				system("pause");

				return 0;
			}
			if (m_pMonster->GetData().iHealth <= 0)
			{
				cout << "승리" << endl;
				system("pause");

				return 1;
			}
			break;
		case(2):
			return 2;
			break;
		case(3):
			m_pSaveCopy->Save(m_pPlayerCopy->GetData(), m_pMonster->GetData());
			break;

		default:
			break;
		}
	}
	
}

