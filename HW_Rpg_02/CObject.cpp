#include "CObject.h"

CObject::CObject()
{
	m_tData = {};
	m_pInventory = nullptr;
}

CObject::CObject(DATA _tObject)
{
	m_pInventory = nullptr;
	m_tData.iName = _tObject.iName;
	m_tData.iHealth = _tObject.iHealth;
	m_tData.iAttackPower = _tObject.iAttackPower;
}

CObject::CObject(DATA _tObject, ITEM* _pInventory, int _iMoney)
{
	m_pInventory = nullptr;
	m_tData.iName = _tObject.iName;
	m_tData.iHealth = _tObject.iHealth;
	m_tData.iAttackPower = _tObject.iAttackPower;
}

CObject::CObject(int _iName, int _iHealth, int _iAttackPower)
{
	m_pInventory = nullptr;
	m_tData.iName = _iName;
	m_tData.iHealth = _iHealth;
	m_tData.iAttackPower = _iAttackPower;
}

CObject::~CObject()
{
	SAFE_DELETE(m_pInventory);
}

void CObject::Render() const
{
}

void CObject::RenderInventory() const
{
}

void CObject::SelectJob()
{
}
