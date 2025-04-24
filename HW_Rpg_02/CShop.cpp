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
		cout << "1. 구매 2. 나가기 :";
		cin >> iInput;

		switch (iInput)
		{
		case(1):
			cout << "구매할 상품 번호를 입력하시오 :";
			cin >> iItemInput;
			if (m_pPlayerCopy->Get_m_iMoney() >= m_tItemArrayInShop[iItemInput - 1].iCost)
			{
				m_pPlayerCopy->SpendMoney(m_tItemArrayInShop[iItemInput-1].iCost);
				m_pPlayerCopy->Plus_m_tInventory_ItemNum(iItemInput - 1);
				cout << "구매 완료" << endl;
				system("pause");
			}
			else
			{
				cout << "캐시가 부족합니다." << endl;
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
	cout << "상점" << endl;
	for (int i = 0; i < ALL_ITEM_TYPE_NUM; i++)
	{
		cout << "=====================================" << endl;
		cout << i+1 << ". " << g_cItemNameArray[i] << endl;
		cout << "가격 : " << m_tItemArrayInShop[i].iCost << endl;
	}
}
