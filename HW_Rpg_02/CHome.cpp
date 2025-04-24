#include "CHome.h"

CHome::CHome()
{
}

CHome::~CHome()
{
}

CHome* CHome::Create()
{
	CHome* pCHome = new CHome();
	return pCHome;
}

void CHome::Initialize()
{
	g_RenderLine(SCREEN_W);
	cout << endl;
	for (int i = 0; i < LOGO_H; i++)
	{
		cout << LogoGraphic[i] << endl;
	}
	cout << endl;
	g_RenderLine(SCREEN_W);
	cout << "시작하려면 아무 키나 누르십시오.." << endl;
	cin.ignore();
}

void CHome::Update()
{
	
}

void CHome::Release()
{
}
