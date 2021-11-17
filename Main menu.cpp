#include<iostream>
#include "ListInit.h"
#include"List.h"
#include "Mainmenu.h"
using namespace std;

// Проверка корректного ввода варианта
int ChoiseVariant(int count)
{
	int variant;
	cout << "Choose variant: ";
	cin >> variant;
	while (variant < 0 or variant>7)
	{
		cout << "Incorrect input. Try again. " << endl;
		cout << "Choose variant: ";
		cin >> variant;
	}
	return variant;
}

// Вывод меню на экран
void PrintMenu()
{
	system("cls");
	cout << "Current list:" << endl;
	Output();
	cout << endl;
	cout << "1. Add to the end of the list." << endl;
	cout << "2. Delete element from the list. " << endl;
	cout << "3. Add to the beginning of the list." << endl;
	cout << "4. Add after element." << endl;
	cout << "5. Add before element" << endl;
	cout << "6. Sort ascending." << endl;
	cout << "7. Linear search." << endl;
	cout << "0. Exit." << endl;
}

// Вывод списка на экран
void Output()
{
	int i;
	List* temp = new List;
	temp = Head;
	for (i = 0; i < NumElem; i++)
	{
		cout << temp->element;
		if (i < NumElem - 1)
		{
			cout << " <-> ";
		}
		temp = temp->next;
	}
}

// Обеспечивает функционал меню
void MainMenu()
{
	vector <int> vectorenter;
	int variant;
	int index;
	int element;
	int sortresult;
	int i;
	do
	{
		PrintMenu();
		variant = ChoiseVariant(7);
		switch (variant)
		{
		case 1:
			cout << "Enter the element: ";
			cin >> element;
			AddEnd(element);
			break;
		case 2:
			cout << "Enter an index from 1 to " << NumElem<<": ";
			cin >> index;
			while (index<1 or index>NumElem)
			{
				cout << "Incorect index. Try again." << endl;
				cout << "Enter an index from 1 to " << NumElem << ": ";
				cin >> index;
			}
			Del(index);
			break;
		case 3:
			cout << "Enter the element: ";
			cin >> element;
			AddBeg(element);
			break;
		case 4:
			cout << "Enter the element: ";
			cin >> element;
			cout << "Enter an index from 1 to " << NumElem << ": ";
			cin >> index;
			while (index<1 or index>NumElem)
			{
				cout << "Incorect index. Try again." << endl;
				cout << "Enter an index from 1 to " << NumElem << ": ";
				cin >> index;
			}
			AddAfter(element,index);
			break;
		case 5:
			cout << "Enter the element: ";
			cin >> element;
			cout << "Enter an index from 1 to " << NumElem << ": ";
			cin >> index;
			while (index<1 or index>NumElem)
			{
				cout << "Incorect index. Try again." << endl;
				cout << "Enter an index from 1 to " << NumElem << ": ";
				cin >> index;
			}
			AddPrev(element, index);
			break;
		case 6:
			Sort();
			break;
		case 7:
			cout << "The element you are lookig for: ";
			cin >> element;
			sortresult = LineSearh(element, vectorenter);
			if (sortresult == 0)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << "Entering = " << sortresult << endl;
				cout << "Index: ";
				for (i = 0; i < sortresult; i++)
				{
					cout << vectorenter[i] << " ";
				}
				cout << endl;
			}
			system("pause");
			break;
		default:
			break;
		}
	} while (variant != 0);
}