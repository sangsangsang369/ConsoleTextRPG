#include "CShop.h"

CShop::CShop()
{
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		m_tItemArrayInShop[i] = g_tItemArray[i];
	}
	m_pPlayerCopy = nullptr;
}

CShop::~CShop()
{
}

CShop* CShop::Create()
{
	CShop* pCShop = new CShop();
	return pCShop;
}

void CShop::Initialize()
{

}

void CShop::Update()
{
	int iInput(0), iItemInput(0);

	while (true)
	{
		system("cls");
		Render();
		g_RenderLine(SCREEN_W);
		cout << endl;
		m_pPlayerCopy->RenderInventory();
		g_RenderLine(SCREEN_W);
		cout << "1. ���� 2. ������ :";
		cin >> iInput;

		switch (iInput)
		{
		case(1):
			cout << "������ ��ǰ ��ȣ�� �Է��Ͻÿ� :";
			cin >> iItemInput;
			if (m_pPlayerCopy->Get_m_pInventory()->Get_m_iMoney() >= m_tItemArrayInShop[iItemInput - 1].iCost)
			{
				m_pPlayerCopy->Get_m_pInventory()->MinusMoney(m_tItemArrayInShop[iItemInput-1].iCost);
				m_pPlayerCopy->Get_m_pInventory()->Plus_m_tInventory_ItemNum(iItemInput - 1);
				cout << "���� �Ϸ�" << endl;
				system("pause");
			}
			else
			{
				cout << "ĳ�ð� �����մϴ�." << endl;
				system("pause");
			}
			break;
		case(2):
			return;
		default:
			break;
		}
	}
}

void CShop::Release()
{
	SAFE_DELETE(m_pPlayerCopy);
}

void CShop::Render() const
{
	g_RenderLine(SCREEN_W);
	cout << "����" << endl;
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		g_RenderLine(SCREEN_W);
		cout << i+1 << ". " << g_cItemNameArray[i] << endl;
		cout << "���� : " << m_tItemArrayInShop[i].iCost << endl;
	}
}
