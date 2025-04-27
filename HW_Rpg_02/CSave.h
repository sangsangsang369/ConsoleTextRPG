#pragma once
#include "CObject.h"

class CSave
{
private:
	FILE* m_pFile;
	DATA m_tDataArray[3];
	ITEM m_tInventory[ALL_ITEM_TYPE_NUM];
	int m_iSavedMoney;

public:
	CSave();
	~CSave();

public:
	static CSave* Create();

public:
	DATA* Get_tDataArray() { return m_tDataArray; }
	ITEM* Get_m_tInventory() { return m_tInventory; }
	int Get_m_iSavedMoney() { return m_iSavedMoney; }

public:
	DATA* CheckSaveFile();
	void Save(CObject* _pCPlayer, DATA _tMonster);
};

