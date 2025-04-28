#pragma once
#include "CObject.h"

class CPlayer : public CObject
{
public:
	CPlayer();
	CPlayer(DATA _tObject, ITEM* _pInventory, int _iMoney);
	~CPlayer();

public:
	static CObject* Create();
	static CObject* Create(DATA _tObject, ITEM* _pInventory, int _iMoney);

public:
	void	Render() const override;
	void	RenderInventory() const override;

	void	SelectJob();
};

