#include "Account.h"

void Account::Deposit(int money)
{
    this->money += money;
}

void Account::Withdraw(int money)
{
    this->money -= money;
}

Account& Account::operator=(const Account& ref)
{
    this->no = ref.no;
    this->name = ref.name;
    this->password = ref.password;
    this->money = ref.money;
    return *this;
}

Account::Account()
    :no("")
    , name("")
    , password("")
    , money(0)
{
}

Account::Account(const Account& ref)
    :no(ref.no)
    , name(ref.name)
    , password(ref.password)
    , money(ref.money)
{
}

Account::Account(string no, string name, string password, int money)
    :no(no)
    , name(name)
    , password(password)
    , money(money)
{
}

Account::~Account()
{
}
