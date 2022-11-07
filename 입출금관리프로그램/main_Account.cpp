#include "AccountHandler.h"

int main(void)
{
	int number = 0;
	AccountHandler handler;
	while (true)
	{
		handler.ShowMenu();
		cin >> number;
		handler.SelectMenu(number);
	}
	return 0;
}