#include "CSave.h"

CSave::CSave()
{
	m_pFile = nullptr;
	m_iSavedMoney = 0;
}

CSave::~CSave()
{
}

CSave* CSave::Create()
{
	CSave* pCSave = new CSave();
	return pCSave;
}

DATA* CSave::CheckSaveFile()
{
	errno_t err = fopen_s(&m_pFile, "../Data/SaveFile.txt", "rb");
	if(0 == err)
	{
		fread(m_tDataArray, sizeof(m_tDataArray), 1, m_pFile);
		fread(m_tInventory, sizeof(m_tInventory), 1, m_pFile);
		fread(&m_iSavedMoney, sizeof(m_iSavedMoney), 1, m_pFile);
		cout << "기록 불러오기 성공" << endl;
		fclose(m_pFile);

		int iInput(0);
		do {
			cout << "이전 플레이 기록이 있습니다. 1. 이어하기, 2. 새로하기 ";
			cin >> iInput;
			system("cls");
		} while (iInput < 1 || iInput > 3);

		switch (iInput)
		{
		case(1):
			return m_tDataArray;
			break;
		case(2):
			return nullptr;
			break;
		}
	}
	else
	{
		return nullptr;
	}
}

void CSave::Save(CPlayer* _pCPlayer, DATA _tMonster)
{
	m_pFile = nullptr;
	m_tDataArray[0] = _pCPlayer->Get_m_tData();
	m_tDataArray[1] = _tMonster;
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		m_tInventory[i] = _pCPlayer->Get_m_tInventoryItem(i);
	}
	m_iSavedMoney = _pCPlayer->Get_m_iMoney();

	errno_t err = fopen_s(&m_pFile, "../Data/SaveFile.txt", "wb");

	if (0 == err)
	{
		fwrite(m_tDataArray, sizeof(m_tDataArray), 1, m_pFile);
		fwrite(m_tInventory, sizeof(m_tInventory), 1, m_pFile);
		fwrite(&m_iSavedMoney, sizeof(m_iSavedMoney), 1, m_pFile);
		fclose(m_pFile);
	}
}
