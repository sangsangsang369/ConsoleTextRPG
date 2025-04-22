#pragma once
#include "CPlayer.h"
#include "CField.h"
#include "CSave.h"

class CMainGame
{
private:
	CPlayer* m_pPlayer;
	CField* m_pField;
	CSave* m_pSave;
	bool m_bFirstCheck;

public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize();
	void	Update();
	void	Release();

};

