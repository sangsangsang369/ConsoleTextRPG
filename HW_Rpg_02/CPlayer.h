#pragma once
#include "CObject.h"

// 1. �ڽ� Ŭ���� ���Ͽ����� �ݵ�� �θ� Ŭ������ ��� ������ �����ؾ� �Ѵ�.
// 2. �ڽ� Ŭ���� �ڷ��� ���� �������� �����ڸ� ����Ѵ�.
class CPlayer : public CObject
{
private:
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
	void SetHealth(int _iHp) { m_tData.iHealth = _iHp; }
	void PlusHealth(int _iHp) { m_tData.iHealth += _iHp; }
	void PlusAttackPower(int _iAttack) { m_tData.iAttackPower += _iAttack; }

public:
	void GetMoney(int _iMoney) { m_iMoney += _iMoney; }
	void SpendMoney(int _iMoney) { m_iMoney -= _iMoney; }

	void Plus_m_tInventory_ItemNum(int _iName) { m_tInventory[_iName].iNumInInventory += 1; }
	void Minus_m_tInventory_ItemNum(int _iName) { m_tInventory[_iName].iNumInInventory -= 1; }

public:
	void RenderInventory() const;
	void SelectJob();
};

