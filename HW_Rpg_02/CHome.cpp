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
	g_RenderLine(LOGO_WINDOW_W);
	cout << endl;
	for (int i = 0; i < LOGO_WINDOW_H; i++)
	{
		cout << LogoGraphic[i] << endl;
	}
	cout << endl;
	g_RenderLine(LOGO_WINDOW_W);
	cout << "�����Ϸ��� �ƹ� Ű�� �����ʽÿ�.." << endl;
	cin.ignore();
}

void CHome::Update()
{
	
}

void CHome::Release()
{
}
