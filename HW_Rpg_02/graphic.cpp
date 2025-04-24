#include "graphic.h"

extern void g_RenderLine(int _iNum)
{
	for (int i = 0; i < _iNum; i++)
	{
		cout << "=";
	}
	cout << endl;
}
