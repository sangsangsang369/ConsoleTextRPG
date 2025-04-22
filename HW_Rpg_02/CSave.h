#pragma once
#include "CPlayer.h"
#include "CMonster.h"

class CSave
{
private:
	FILE* pFile;
	DATA tDataArray[3];

public:
	CSave();
	~CSave();

	DATA* Get_tDataArray() { return tDataArray; }

public:
	DATA* CheckSaveFile();
	void Save(DATA _tPlayer, DATA _tMonster);
};

