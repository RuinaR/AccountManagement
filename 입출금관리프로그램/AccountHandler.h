#pragma once
#include "Account.h"
#define MAX 100

class AccountHandler
{
public:
	enum
	{
		REGISTER = 1,		//1. ���常���
		BALANCE,				//2. �ܾ���ȸ
		DEPOSIT,				//3. �Ա��ϱ�
		WITHDRAW,			//4. ����ϱ�
		TOTAL,					//5. ��ü���庸��
		DELETEACCOUNT,	//6. ���»����ϱ�
		EXIT						//7. �����ϱ�
	};
	void ShowMenu(void);
	void SelectMenu(int number);
	void RegisterMenu(void);
	void DepositMenu(void);
	void WithdrawMenu(void);
	void BalanceMenu(void);
	void TotalMenu(void);
	void DeleteAccountMenu(void);
	void ExitMenu(void);
	//�⺻�ڵ�
	AccountHandler& operator= (const AccountHandler& ref);	//x
	AccountHandler(const AccountHandler& ref);					//x
	AccountHandler();
	~AccountHandler();
	//get
	inline int GetCount()const { return this->count; }

private:
	Account* account[MAX];
	int count;	//���� �迭 ������ ����
};

