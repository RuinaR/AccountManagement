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
	cout << "\t����ݰ��� ���α׷�" << endl;
	cout << "-----------------------------------" << endl;
	cout << "1.���常���(���°���)" << endl;
	cout << "2.�ܾ���ȸ�ϱ�" << endl;
	cout << "3.�Ա��ϱ�" << endl;
	cout << "4.����ϱ�" << endl;
	cout << "5.��ü���庸��" << endl;
	cout << "6.���»����ϱ�" << endl;
	cout << "7.�����ϱ�" << endl;
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
		cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�." << endl;
	}
}

void AccountHandler::RegisterMenu(void)
{
	string no = "";
	string name = "";
	string password = "";
	int money = 0;
	cout << "[���常���](���°���) �Դϴ�" << endl;
	cout << "1.�����ȣ�� �Է��ϼ��� : ";
	cin >> no;
	cout << "2.������ �̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << "3.��й�ȣ�� �Է��ϼ��� : ";
	cin >> password;
	cout << "4.�ܾ��� �Է��ϼ��� : ";
	cin >> money;
	this->account[count] = new Account(no, name, password, money);
	this->count++;

	cout << "���°����Ϸ�" << endl;
}

void AccountHandler::DepositMenu(void)
{
	int money = 0;
	string no = "";
	string password = "";
	cout << "[�Ա��ϱ�] �Դϴ�." << endl;
	cout << "1.�����ȣ�� �Է��ϼ��� : ";
	cin >> no;
	cout << "2.��й�ȣ�� �Է��ϼ��� : ";
	cin >> password;
	for (int i = 0; i < this->count; i++)
	{
		if ((no == this->account[i]->GetNo()) &&
			(password == this->account[i]->GetPassword()))
		{
			cout << "3.�Աݾ��� �Է��ϼ��� : ";
			cin >> money;
			if (money <= 0)
			{
				cout << "0 ������ �ݾ��� �Ա��� �� �����." << endl;
				return;
			}
			this->account[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "�����ȣ�� ���ų� ��й�ȣ�� ��ġ���� �ʾƿ�." << endl;
}

void AccountHandler::WithdrawMenu(void)
{
	int money = 0;
	string no = "";
	string password = "";
	cout << "[����ϱ�] �Դϴ�." << endl;
	cout << "1.�����ȣ�� �Է��ϼ��� : ";
	cin >> no;
	cout << "2.��й�ȣ�� �Է��ϼ��� : ";
	cin >> password;
	for (int i = 0; i < this->count; i++)
	{
		if ((no == this->account[i]->GetNo()) &&
			(password == this->account[i]->GetPassword()))
		{
			cout << "3.��ݾ��� �Է��ϼ��� : ";
			cin >> money;
			if (money > this->account[i]->GetMoney())
			{
				cout << "���忡 �ִ� �ݾ׺��� ū �ݾ��� ����� �� �����." << endl;
				return;
			}
			this->account[i]->Withdraw(money);
			cout << "��ݿϷ�" << endl;
			return;
		}
	}
	cout << "�����ȣ�� ���ų� ��й�ȣ�� ��ġ���� �ʾƿ�." << endl;
}

void AccountHandler::BalanceMenu(void)
{
	string no = "";
	string password = "";
	cout << "[�ܾ���ȸ�ϱ�] �Դϴ�." << endl;
	cout << "1.�����ȣ�� �Է��ϼ��� : ";
	cin >> no;
	cout << "2.��й�ȣ�� �Է��ϼ��� : ";
	cin >> password;
	for (int i = 0; i < this->count; i++)
	{
		if ((no == this->account[i]->GetNo()) &&
			(password == this->account[i]->GetPassword()))
		{
			cout << "�����ȣ\t�̸�\t�ܾ�(��)" << endl;
			cout << this->account[i]->GetNo() << "\t\t" << this->account[i]->GetName() << "\t" << this->account[i]->GetMoney() << "��" << endl;
			return;
		}
	}
	cout << "�����ȣ�� ���ų� ��й�ȣ�� ��ġ���� �ʾƿ�." << endl;
}

void AccountHandler::TotalMenu(void)
{
	cout << "[��ü���庸��] �Դϴ�." << endl;
	cout << "--------------------------------------" << endl;
	cout << "��ȣ\t�����ȣ\t�̸�\t�ܾ�(��)" << endl;
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < this->count; i++)
	{
		cout << i + 1 << "\t"
			<< this->account[i]->GetNo() << "\t\t"
			<< this->account[i]->GetName() << "\t"
			<< this->account[i]->GetMoney() << "��" << endl;
	}
}

void AccountHandler::DeleteAccountMenu(void)
{
	string no = "";
	string password = "";
	cout << "[���»����ϱ�] �Դϴ�." << endl;
	cout << "1.�����ȣ�� �Է��ϼ��� : ";
	cin >> no;
	cout << "2.��й�ȣ�� �Է��ϼ��� : ";
	cin >> password;
	for (int i = 0; i < this->count; i++)
	{
		if ((no == this->account[i]->GetNo()) &&
			(password == this->account[i]->GetPassword()))
		{
			delete this->account[i];	//ã�� ���¸� ������ ��
			for (int j = i; j < this->count - 1; j++)	//�����͸� ��ĭ�� ���� ����
			{
				this->account[j] = this->account[j + 1];
			}
			this->count--;	//ī��Ʈ --
			cout << "���¸� �����߾��" << endl;
			return;
		}
	}
	cout << "�����ȣ�� ���ų� ��й�ȣ�� ��ġ���� �ʾƿ�." << endl;
}

void AccountHandler::ExitMenu(void)
{
	for (int i = 0; i < this->count; i++)
	{
		delete  this->account[i];
	}
	cout << "���α׷��� �����մϴ�." << endl;
	exit(0);
}

