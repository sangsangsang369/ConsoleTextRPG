#pragma once
#include "pch.h"
#include "define.h"

class CPlayer
{
private:
	DATA m_tData;
	const char* m_cPlayerName[NAME_ARRAY_SIZE];

public:
	CPlayer();
	CPlayer(DATA _tPlayer);
	~CPlayer();

public:
	static CPlayer* Create();
	static CPlayer* Create(DATA _tPlayer);

	DATA GetData() const { return m_tData; }
	void GetDamage(int _iAttack) { m_tData.iHealth -= _iAttack; }
	void SetHealth(int _iHp) { m_tData.iHealth = _iHp; }

public:
	void Render() const;
	void SelectJob();
};

