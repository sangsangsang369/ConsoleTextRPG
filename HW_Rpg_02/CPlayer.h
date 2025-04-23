#pragma once
#include "pch.h"
#include "define.h"

class CPlayer
{
private:
	DATA m_tData;
	ITEM m_tInventory[ALL_ITEM_TYPE_NUM];
	int m_iMoney;

public:
	CPlayer();
	CPlayer(DATA _tPlayer, ITEM* _pInventory, int _iMoney);
	~CPlayer();

public:
	static CPlayer* Create();
	static CPlayer* Create(DATA _tPlayer, ITEM* _pInventory, int _iMoney);

public:
	DATA Get_m_tData() const { return m_tData; }
	int Get_m_iMoney() { return m_iMoney; }
	ITEM* Get_m_tInventory() { return m_tInventory; }
	ITEM Get_m_tInventoryItem(int _iIndex) { return m_tInventory[_iIndex]; }

public:
	void GetDamage(int _iAttack) { m_tData.iHealth -= _iAttack; }
	void SetHealth(int _iHp) { m_tData.iHealth = _iHp; }
	void GetMoney(int _iMoney) { m_iMoney += _iMoney; }
	void SpendMoney(int _iMoney) { m_iMoney -= _iMoney; }
	void Set_m_tInventory_ItemNum(int _iName) { m_tInventory[_iName].iNumInInventory += 1; }

public:
	void Render() const;
	void RenderInventory() const;
	void SelectJob();
};

