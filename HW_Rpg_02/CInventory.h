#pragma once
#include "pch.h"
#include "define.h"

class CInventory
{
private:
	ITEM	m_tInventory[ALL_ITEM_TYPE_NUM];
	int		m_iMoney;

public:
	CInventory();
	CInventory(ITEM* _pInventory, int _iMoney);

public:
	static CInventory* Create();
	static CInventory* Create(ITEM* _pInventory, int _iMoney);

public:
	int		Get_m_iMoney() { return m_iMoney; }
	void	Set_m_iMoney(int _iMoney) { m_iMoney = _iMoney; }
	ITEM*	Get_m_tInventory() { return m_tInventory; }
	ITEM	Get_m_tInventoryItem(int _iIndex) { return m_tInventory[_iIndex]; }
	
public:
	void	PlusMoney(int _iMoney) { m_iMoney += _iMoney; }
	void	MinusMoney(int _iMoney) { m_iMoney -= _iMoney; }

	void	Plus_m_tInventory_ItemNum(int _iName) { m_tInventory[_iName].iNumInInventory += 1; }
	void	Minus_m_tInventory_ItemNum(int _iName) { m_tInventory[_iName].iNumInInventory -= 1; }
};

