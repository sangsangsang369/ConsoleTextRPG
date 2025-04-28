#pragma once
#include "pch.h"
#include "define.h"
#include "CInventory.h"

class CObject
{
protected:
	DATA		m_tData;
	CInventory* m_pInventory;

public:
	CObject();
	CObject(DATA _tObject);
	CObject(DATA _tObject, ITEM* _pInventory, int _iMoney);
	CObject(int _iName, int _iHealth, int _iAttackPower);
	virtual ~CObject();
	
public:
	DATA		Get_m_tData() const { return m_tData; }
	CInventory* Get_m_pInventory() const { return m_pInventory; }

public:
	void	ResetHealth(int _iHp) { m_tData.iHealth = _iHp; }
	void	PlusHealth(int _iHp) { m_tData.iHealth += _iHp; }
	void	PlusAttackPower(int _iAttack) { m_tData.iAttackPower += _iAttack; }
	void	MinusHealthByAttack(int _iAttack) { m_tData.iHealth -= _iAttack; }

// 가상 함수 (플레이어용)
public:
	virtual void Render() const;
	virtual void RenderInventory() const;
};

