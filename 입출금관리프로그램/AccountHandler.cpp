#include "AccountHandler.h"
using namespace std;


AccountHandler& AccountHandler::operator=(const AccountHandler& ref)
{
	this->count = ref.count;
	for (int i = 0; i < this->count; i++)
	{
		this->account[i] = ref.account[i];
	}
	return *this;
}

AccountHandler::AccountHandler(const AccountHandler& ref)
	:count(ref.count)
{
	for (int i = 0; i < this->count; i++)
	{
		this->account[i] = ref.account[i];
	}
}

AccountHandler::AccountHandler()
	:count(0)
{

}

AccountHandler::~AccountHandler()
{

}


void AccountHandler::ShowMenu(void)
{
	cout << "-----------------------------------" << endl;
	cout << "\t입출금관리 프로그램" << endl;
	cout << "-----------------------------------" << endl;
	cout << "1.통장만들기(계좌개설)" << endl;
	cout << "2.잔액조회하기" << endl;
	cout << "3.입금하기" << endl;
	cout << "4.출금하기" << endl;
	cout << "5.전체통장보기" << endl;
	cout << "6.계좌삭제하기" << endl;
	cout << "7.종료하기" << endl;
	cout << "-----------------------------------" << endl;
	cout << ">>";
}

void AccountHandler::SelectMenu(int number)
{
	system("cls");
	switch (number)
	{
	case REGISTER:
		this->RegisterMenu();
		break;
	case BALANCE:
		this->BalanceMenu();
		break;
	case DEPOSIT:
		this->DepositMenu();
		break;
	case WITHDRAW:
		this->WithdrawMenu();
		break;
	case TOTAL:
		this->TotalMenu();
		break;
	case DELETEACCOUNT:
		this->DeleteAccountMenu();
		break;
	case EXIT:
		this->ExitMenu();
		break;
	default:
		cout << "잘못된 번호를 입력하셨습니다." << endl;
	}
}

void AccountHandler::RegisterMenu(void)
{
	string no = "";
	string name = "";
	string password = "";
	int money = 0;
	cout << "[통장만들기](계좌개설) 입니다" << endl;
	cout << "1.통장번호를 입력하세요 : ";
	cin >> no;
	cout << "2.소유주 이름을 입력하세요 : ";
	cin >> name;
	cout << "3.비밀번호를 입력하세요 : ";
	cin >> password;
	cout << "4.잔액을 입력하세요 : ";
	cin >> money;
	this->account[count] = new Account(no, name, password, money);
	this->count++;

	cout << "계좌개설완료" << endl;
}

void AccountHandler::DepositMenu(void)
{
	int money = 0;
	string no = "";
	string password = "";
	cout << "[입금하기] 입니다." << endl;
	cout << "1.통장번호를 입력하세요 : ";
	cin >> no;
	cout << "2.비밀번호를 입력하세요 : ";
	cin >> password;
	for (int i = 0; i < this->count; i++)
	{
		if ((no == this->account[i]->GetNo()) &&
			(password == this->account[i]->GetPassword()))
		{
			cout << "3.입금액을 입력하세요 : ";
			cin >> money;
			if (money <= 0)
			{
				cout << "0 이하의 금액은 입금할 수 없어요." << endl;
				return;
			}
			this->account[i]->Deposit(money);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "통장번호가 없거나 비밀번호가 일치하지 않아요." << endl;
}

void AccountHandler::WithdrawMenu(void)
{
	int money = 0;
	string no = "";
	string password = "";
	cout << "[출금하기] 입니다." << endl;
	cout << "1.통장번호를 입력하세요 : ";
	cin >> no;
	cout << "2.비밀번호를 입력하세요 : ";
	cin >> password;
	for (int i = 0; i < this->count; i++)
	{
		if ((no == this->account[i]->GetNo()) &&
			(password == this->account[i]->GetPassword()))
		{
			cout << "3.출금액을 입력하세요 : ";
			cin >> money;
			if (money > this->account[i]->GetMoney())
			{
				cout << "통장에 있는 금액보다 큰 금액은 출금할 수 없어요." << endl;
				return;
			}
			this->account[i]->Withdraw(money);
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "통장번호가 없거나 비밀번호가 일치하지 않아요." << endl;
}

void AccountHandler::BalanceMenu(void)
{
	string no = "";
	string password = "";
	cout << "[잔액조회하기] 입니다." << endl;
	cout << "1.통장번호를 입력하세요 : ";
	cin >> no;
	cout << "2.비밀번호를 입력하세요 : ";
	cin >> password;
	for (int i = 0; i < this->count; i++)
	{
		if ((no == this->account[i]->GetNo()) &&
			(password == this->account[i]->GetPassword()))
		{
			cout << "통장번호\t이름\t잔액(원)" << endl;
			cout << this->account[i]->GetNo() << "\t\t" << this->account[i]->GetName() << "\t" << this->account[i]->GetMoney() << "원" << endl;
			return;
		}
	}
	cout << "통장번호가 없거나 비밀번호가 일치하지 않아요." << endl;
}

void AccountHandler::TotalMenu(void)
{
	cout << "[전체통장보기] 입니다." << endl;
	cout << "--------------------------------------" << endl;
	cout << "번호\t통장번호\t이름\t잔액(원)" << endl;
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < this->count; i++)
	{
		cout << i + 1 << "\t"
			<< this->account[i]->GetNo() << "\t\t"
			<< this->account[i]->GetName() << "\t"
			<< this->account[i]->GetMoney() << "원" << endl;
	}
}

void AccountHandler::DeleteAccountMenu(void)
{
	string no = "";
	string password = "";
	cout << "[계좌삭제하기] 입니다." << endl;
	cout << "1.통장번호를 입력하세요 : ";
	cin >> no;
	cout << "2.비밀번호를 입력하세요 : ";
	cin >> password;
	for (int i = 0; i < this->count; i++)
	{
		if ((no == this->account[i]->GetNo()) &&
			(password == this->account[i]->GetPassword()))
		{
			delete this->account[i];	//찾은 계좌를 삭제한 후
			for (int j = i; j < this->count - 1; j++)	//데이터를 한칸씩 전부 당긴다
			{
				this->account[j] = this->account[j + 1];
			}
			this->count--;	//카운트 --
			cout << "계좌를 삭제했어요" << endl;
			return;
		}
	}
	cout << "통장번호가 없거나 비밀번호가 일치하지 않아요." << endl;
}

void AccountHandler::ExitMenu(void)
{
	for (int i = 0; i < this->count; i++)
	{
		delete  this->account[i];
	}
	cout << "프로그램을 종료합니다." << endl;
	exit(0);
}

