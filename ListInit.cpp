#include"ListInit.h"
#include"List.h"

// ������������� ���������� ����������
//
List* Tail = 0;// ����� ������
List* Head = 0;// ������ ������
int NumElem = 0;// ���������� ��������� � ������
//

// ������������� ������� ���������� ���������� �� -50 �� 50
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