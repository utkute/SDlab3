#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include "List.h"
#include "ListInit.h"
#include"Mainmenu.h"
using namespace std;

int main()
{
	srand(time(0));
	int startQuantity;
	cout << "Enter the initial number of elements: ";
	cin >> startQuantity;
	Init(startQuantity);
	MainMenu();
	return 0;
}