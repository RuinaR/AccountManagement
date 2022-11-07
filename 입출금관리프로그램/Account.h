#pragma once
#pragma once
#include <iostream>
using namespace std;
class Account
{
public:
	//추가함수
	void Deposit(int money);
	void Withdraw(int money);
	//operator=
	Account& operator=(const Account& ref);
	//constructor/destructor
	Account();
	Account(const Account& ref);
	Account(string no, string name, string password, int money);
	~Account();
	//getter/setter
	inline string GetNo(void)const { return this->no; }
	inline void SetNo(string no) { this->no = no; }
	inline string GetName(void)const { return this->name; }
	inline void SetName(string name) { this->name = name; }
	inline string GetPassword(void)const { return this->password; }
	inline void SetPassword(string password) { this->password = password; }
	inline int GetMoney(void)const { return this->money; }
	inline void SetMoney(int money) { this->money = money; }
private:
	string no;
	string name;
	string password;
	int money;
};

