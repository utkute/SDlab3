#include"ListInit.h"
#include"List.h"

// Инициализация глобальный переменных
//
List* Tail = 0;// Конец списка
List* Head = 0;// Начало списка
int NumElem = 0;// Колличесво элементов в списке
//

// Инициализация массива случайными значениями от -50 до 50
void Init(int startQuantity)
{
	int i;
	int elem;
	for (i = 0; i < startQuantity; i++)
	{
		elem = rand() % 100 - 50;
		AddEnd(elem);
	}
}