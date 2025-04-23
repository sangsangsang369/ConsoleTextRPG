#pragma once
#include "define.h"

class CInventory
{
private:
	ITEM m_tItemArray[ALL_ITEM_TYPE_NUM];

public:
	CInventory();

public: 
	ITEM* Get_m_tItemArray() { return m_tItemArray; }
	void Buy_m_tItemArray(int _iName, int _iNum) { m_tItemArray[_iName].iNumInInventory += _iNum; }
	void Use_m_tItemArray(int _iName) { m_tItemArray[_iName].iNumInInventory -= 1; }
};

