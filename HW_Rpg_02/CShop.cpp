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
		cout << "=====================================" << endl << endl;
		m_pPlayerCopy->RenderInventory();
		cout << "=====================================" << endl;
		cout << "1. ���� 2. ������ :";
		cin >> iInput;

		switch (iInput)
		{
		case(1):
			cout << "������ ��ǰ ��ȣ�� �Է��Ͻÿ� :";
			cin >> iItemInput;
			if (m_pPlayerCopy->Get_m_iMoney() >= m_tItemArrayInShop[iItemInput - 1].iCost)
			{
				m_pPlayerCopy->SpendMoney(m_tItemArrayInShop[iItemInput-1].iCost);
				m_pPlayerCopy->Plus_m_tInventory_ItemNum(iItemInput - 1);
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
	cout << "=====================================" << endl;
	cout << "����" << endl;
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		cout << "=====================================" << endl;
		cout << i+1 << ". " << g_cItemNameArray[i] << endl;
		cout << "���� : " << m_tItemArrayInShop[i].iCost << endl;
	}
}
