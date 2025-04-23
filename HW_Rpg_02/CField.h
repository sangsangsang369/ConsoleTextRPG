#pragma once
#include "pch.h"
#include "define.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CSave.h"

class CField
{
private:
	CPlayer* m_pPlayerCopy;
	CMonster* m_pMonster;
	CSave* m_pSaveCopy;

public:
	CField();
	CField(CSave* _pSave);
	~CField();

public:
	static CField* Create();
	static CField* Create(CSave* _pSave);

	void Set_pPlayerCopy(CPlayer* _pPlayer) { m_pPlayerCopy = _pPlayer; };
	void Set_pMonsterFromSaveFile();

public:
	void	Initialize();
	void	Update();
	void	Release();

	int Fight();
};

