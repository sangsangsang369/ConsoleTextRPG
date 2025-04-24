#pragma once
#include "pch.h"
#include "graphic.h"

class CHome
{
public:
	CHome();
	~CHome();

	static CHome* Create();

public:
	void	Initialize();
	void	Update();
	void	Release();
};

