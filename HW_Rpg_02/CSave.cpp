#include "CSave.h"

CSave::CSave()
{
    pFile = nullptr;
}

CSave::~CSave()
{
}

CSave* CSave::Create()
{
	CSave* pCSave = new CSave();
	return pCSave;
}

DATA* CSave::CheckSaveFile()
{
	errno_t err = fopen_s(&pFile, "../Data/SaveFile.txt", "rb");
	if(0 == err)
	{
		fread(tDataArray, sizeof(tDataArray), 1, pFile);
		cout << "��� �ҷ����� ����" << endl;
		fclose(pFile);

		int iInput(0);
		do {
			cout << "���� �÷��� ����� �ֽ��ϴ�. 1. �̾��ϱ�, 2. �����ϱ� ";
			cin >> iInput;
			system("cls");
		} while (iInput < 1 || iInput > 3);

		switch (iInput)
		{
		case(1):
			return tDataArray;
			break;
		case(2):
			return nullptr;
			break;
		}
	}
	else
	{
		return nullptr;
	}
}

void CSave::Save(DATA _tPlayer, DATA _tMonster)
{
	pFile = nullptr;
	tDataArray[0] = _tPlayer;
	tDataArray[1] = _tMonster;
	errno_t err = fopen_s(&pFile, "../Data/SaveFile.txt", "wb");

	if (0 == err)
	{
		fwrite(tDataArray, sizeof(tDataArray), 1, pFile);
		fclose(pFile);
	}
}
