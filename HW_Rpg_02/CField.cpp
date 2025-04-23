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

CField* CField::Create()
{
	CField* pCField = new CField();
	return pCField;
}

CField* CField::Create(CSave* _pSave)
{
	CField* pCField = new CField(_pSave);
	return pCField;
}

void CField::Set_pMonsterFromSaveFile()
{
	if (m_pSaveCopy)
	{
		m_pMonster = CMonster::Create(m_pSaveCopy->Get_tDataArray()[1]);
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
				cout << "1. ÃÊ±Þ 2. Áß±Þ 3. °í±Þ 4. Àü ´Ü°è : ";
				cin >> iInput;
				system("cls");
			} while (iInput < 1 || iInput > 4);

			switch (iInput)
			{
			case(1):
			case(2):
			case(3):
				m_pMonster = CMonster::Create(iInput - 1, 30 * iInput, 3 * iInput);
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
			cout << "1. °ø°Ý 2. µµ¸Á 3. ÀúÀå: ";
			cin >> iInput;
		} while (iInput < 1 || iInput > 3);

		switch (iInput)
		{
		case(1):
			m_pPlayerCopy->GetDamage(m_pMonster->Get_m_tData().iAttackPower);
			m_pMonster->GetDamage(m_pPlayerCopy->Get_m_tData().iAttackPower);

			if (m_pPlayerCopy->Get_m_tData().iHealth <= 0)
			{
				cout << "»ç¸Á" << endl;
				system("pause");

				return 0;
			}
			if (m_pMonster->Get_m_tData().iHealth <= 0)
			{
				cout << "½Â¸®" << endl;
				cout << m_pMonster->Get_m_tData().iAttackPower * MONEY_WEIGHT << "¸Ó´Ï È¹µæ" << endl << endl;
				system("pause");
				m_pPlayerCopy->GetMoney(m_pMonster->Get_m_tData().iAttackPower * MONEY_WEIGHT);
				return 1;
			}
			break;
		case(2):
			return 2;
			break;
		case(3):
			m_pSaveCopy->Save(m_pPlayerCopy, m_pMonster->Get_m_tData());
			break;

		default:
			break;
		}
	}
}

