#pragma once
#include "pch.h"
#include "define.h"
#include "CObject.h"

class CShop
{
private:
	ITEM m_tItemArrayInShop[ALL_ITEM_TYPE_NUM];
	CObject* m_pPlayerCopy;

public:
	CShop();
	~CShop();

public:
	static CShop* Create();
	void Set_pPlayerCopy(CObject* _pPlayer) { m_pPlayerCopy = _pPlayer; };

public:
	void	Initialize();
	void	Update();
	void	Release();

	void Render() const;
};

