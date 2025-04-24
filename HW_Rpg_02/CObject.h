#pragma once
#include "pch.h"
#include "define.h"

// 전역함수
//extern void g_RenderLine(int _iNum);

class CObject
{
protected:
	DATA m_tData;

public:
	CObject();

public:
	DATA Get_m_tData() const { return m_tData; }

public:
	void GetDamage(int _iAttack) { m_tData.iHealth -= _iAttack; }public:
	void Render(int _iType) const;
};

