#pragma once
#include "Account.h"
#define MAX 100

class AccountHandler
{
public:
	enum
	{
		REGISTER = 1,		//1. 통장만들기
		BALANCE,				//2. 잔액조회
		DEPOSIT,				//3. 입금하기
		WITHDRAW,			//4. 출금하기
		TOTAL,					//5. 전체통장보기
		DELETEACCOUNT,	//6. 계좌삭제하기
		EXIT						//7. 종료하기
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
	//기본코딩
	AccountHandler& operator= (const AccountHandler& ref);	//x
	AccountHandler(const AccountHandler& ref);					//x
	AccountHandler();
	~AccountHandler();
	//get
	inline int GetCount()const { return this->count; }

private:
	Account* account[MAX];
	int count;	//현재 배열 데이터 개수
};

