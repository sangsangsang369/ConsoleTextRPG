#pragma once
#include "CObject.h"

class CMonster : public CObject
{
public:
	CMonster();
	CMonster(DATA _tObject);
	CMonster(int _iName, int _iHealth, int _iAttackPower);
	~CMonster();

public:
	static CObject* Create();
	static CObject* Create(DATA _tObject);
	static CObject* Create(int _iName, int _iHealth, int _iAttackPower);

public:
	void Render() const;
};

