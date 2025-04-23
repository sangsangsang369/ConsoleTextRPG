#pragma once
#include "CPlayer.h"
#include "CField.h"
#include "CShop.h"
#include "CSave.h"

class CMainGame
{
private:
	CPlayer* m_pPlayer;
	CField* m_pField;
	CShop* m_pShop;
	CSave* m_pSave;
	bool m_bFirstCheck;
	DATA* m_tDataArray;

public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize();
	void	Update();
	void	Release();

};

