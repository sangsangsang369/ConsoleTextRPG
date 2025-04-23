#pragma once
#include "pch.h"
#include "define.h"
#include "CPlayer.h"

class CShop
{
private:
	ITEM m_tItemArrayInShop[ALL_ITEM_TYPE_NUM];
	CPlayer* m_pPlayerCopy;

public:
	CShop();
	~CShop();

public:
	static CShop* Create();
	void Set_pPlayerCopy(CPlayer* _pPlayer) { m_pPlayerCopy = _pPlayer; };

public:
	void	Initialize();
	void	Update();
	void	Release();

	void Render() const;
};

