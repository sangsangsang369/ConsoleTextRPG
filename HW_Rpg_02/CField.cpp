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
				cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
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
			m_pPlayerCopy->ResetHealth(100);
			SAFE_DELETE(m_pMonster);
			break;
		case(1):
			SAFE_DELETE(m_pMonster);
			break;
		case(2):
			SAFE_DELETE(m_pMonster);
			break;
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
			cout << "1. 공격 2. 도망 3. 저장 4. 아이템: ";
			cin >> iInput;
		} while (iInput < 1 || iInput > 4);

		int iItemNum(0);
		switch (iInput)
		{
		case(1):
			m_pPlayerCopy->MinusHealthByAttack(m_pMonster->Get_m_tData().iAttackPower);
			m_pMonster->MinusHealthByAttack(m_pPlayerCopy->Get_m_tData().iAttackPower);

			if (m_pPlayerCopy->Get_m_tData().iHealth <= 0)
			{
				cout << "사망" << endl;
				system("pause");

				return 0;
			}
			if (m_pMonster->Get_m_tData().iHealth <= 0)
			{
				cout << "승리" << endl;
				cout << m_pMonster->Get_m_tData().iAttackPower * MONEY_WEIGHT << "머니 획득" << endl << endl;
				system("pause");
				m_pPlayerCopy->Get_m_pInventory()->PlusMoney(m_pMonster->Get_m_tData().iAttackPower * MONEY_WEIGHT);
				return 1;
			}
			break;
		case(2):
			return 2;
			break;
		case(3):
			m_pSaveCopy->Save(m_pPlayerCopy, m_pMonster->Get_m_tData());
			break;
		case(4):
			while (true)
			{
				do {
					system("cls");
					m_pPlayerCopy->Render();
					m_pPlayerCopy->RenderInventory();
					cout << "사용하고자 하는 아이템의 번호를 입력하시오. (나가기 : 0) : ";
					cin >> iItemNum;
				} while (m_pPlayerCopy->Get_m_pInventory()->Get_m_tInventoryItem(iItemNum - 1).iNumInInventory == 0);
				
				switch (iItemNum)
				{
				case(POTION):
					m_pPlayerCopy->Get_m_pInventory()->Minus_m_tInventory_ItemNum(iItemNum - 1);
					m_pPlayerCopy->PlusHealth(g_tItemArray[iItemNum - 1].iWeight);
					break;
				case(AMPLIFIER):
					m_pPlayerCopy->Get_m_pInventory()->Minus_m_tInventory_ItemNum(iItemNum - 1);
					m_pPlayerCopy->PlusAttackPower(g_tItemArray[iItemNum - 1].iWeight);
					break;
				case(0):
					break;
				default:
					break;
				}
				break;
			}
			break;
		}
	}
}

