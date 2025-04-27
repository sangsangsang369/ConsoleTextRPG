#pragma once
#include "pch.h"
#include "define.h"

class CObject
{
protected:
	DATA m_tData;

protected:
	ITEM	m_tInventory[ALL_ITEM_TYPE_NUM];
	int		m_iMoney;

public:
	CObject();
	CObject(DATA _tObject);
	CObject(DATA _tObject, ITEM* _pInventory, int _iMoney);
	CObject(int _iName, int _iHealth, int _iAttackPower);
	virtual ~CObject();
	
public:
	DATA	Get_m_tData() const { return m_tData; }
	void	GetDamage(int _iAttack) { m_tData.iHealth -= _iAttack; }
	void	SetHealth(int _iHp) { m_tData.iHealth = _iHp; }
	void	PlusHealth(int _iHp) { m_tData.iHealth += _iHp; }
	void	PlusAttackPower(int _iAttack) { m_tData.iAttackPower += _iAttack; }

public:
	int		Get_m_iMoney() { return m_iMoney; }
	void	GetMoney(int _iMoney) { m_iMoney += _iMoney; }
	void	SpendMoney(int _iMoney) { m_iMoney -= _iMoney; }

public:
	ITEM*	Get_m_tInventory() { return m_tInventory; }
	ITEM	Get_m_tInventoryItem(int _iIndex) { return m_tInventory[_iIndex]; }
	void	Plus_m_tInventory_ItemNum(int _iName) { m_tInventory[_iName].iNumInInventory += 1; }
	void	Minus_m_tInventory_ItemNum(int _iName) { m_tInventory[_iName].iNumInInventory -= 1; }


// 가상 함수 (플레이어용)
public:
	virtual void Render() const;
	virtual void RenderInventory() const;
	virtual void SelectJob();

};

