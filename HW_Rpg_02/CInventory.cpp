#include "CInventory.h"

CInventory::CInventory()
{
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		m_tInventory[i] = g_tItemArray[i];
	}
	m_iMoney = 0;
}

CInventory::CInventory(ITEM* _pInventory, int _iMoney)
{
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		m_tInventory[i] = _pInventory[i];
	}
	m_iMoney = _iMoney;
}

CInventory* CInventory::Create()
{
	CInventory* pInventory = new CInventory();
	return pInventory;
}

CInventory* CInventory::Create(ITEM* _pInventory, int _iMoney)
{
	CInventory* pInventory = new CInventory(_pInventory, _iMoney);
	return pInventory;
}

