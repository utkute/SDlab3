#include "ListInit.h"
#include"List.h"
using namespace std;

// ���������� �������� � �����
void AddEnd(int element)
{
	List* temp = new List;
	temp->element = element;
	temp->next = 0;
	temp->previous = Tail;
	if (Tail == 0)//���� ������� ������
	{
		Tail = Head = temp;
	}
	else
	{
		Tail->next = temp;
		Tail = temp;
	}
	NumElem++;
}

// ���������� �������� � ������
void AddBeg(int element)
{
	List* temp = new List;
	temp->element = element;
	temp->next = Head;
	temp->previous = 0;
	if (Tail == 0)
	{
		Tail = Head = temp;
	}
	else
	{
		Head->previous = temp;
		Head = temp;
	}
	NumElem++;
}

// �������� ��������
void Del(int index)
{
	int i = 1;
	List* rem = new List;// ��������� �������
	rem = Head;
	while (i < index)
	{
		rem = rem->next;
		i++;
	}
	List* prevrem = new List;// ���������� �� ����������
	List* afterrem = new List;// ��������� ����� ����������
	prevrem = rem->previous;
	afterrem = rem->next;
	if (index == 1)// ���� ��������� ������ ��� ����� �� ������� ��
	{
		Head = afterrem;
	}
	else if (index == NumElem)
	{
		Tail = prevrem;
	}//
	else
	{
		prevrem->next = afterrem;
		afterrem->previous = prevrem;
	}
	delete rem;
	NumElem--;
}

// ������� ����� ��������
void AddAfter(int element, int index)
{
	List* temp = new List;
	List* prevadd = new List;
	List* afteradd = new List;
	int i = 1;
	prevadd = Head;
	while (i != index)
	{
		prevadd = prevadd->next;
		i++;
	}
	afteradd = prevadd->next;
	if (index == NumElem)
	{
		Tail = temp;
	}
	temp->element = element;
	temp->next = afteradd;
	temp->previous = prevadd;
	prevadd->next = temp;
	afteradd->previous = temp;
	NumElem++;
}

// ������� ����� ���������
void AddPrev(int element, int index)
{
	List* temp = new List;
	List* afteradd = new List;
	List* prevadd = new List;
	int i = 1;
	afteradd = Head;
	while (i != index)
	{
		afteradd = afteradd->next;
		i++;
	}
	prevadd = afteradd->previous;
	if (index == 1)
	{
		Head = temp;
	}
	temp->element = element;
	temp->previous = prevadd;
	temp->next = afteradd;
	afteradd->previous = temp;
	prevadd->next = temp;
	NumElem++;
}

// ���������� �� ����������� ���������
void Sort()
{
	List* fsort = new List;
	List* min = new List;
	List* temp = new List;
	int i;
	int t;
	int sortindex = 0;
	int counter = NumElem;
	min = Head;
	fsort = Head;
	temp = Head;
	while (sortindex < NumElem)
	{
		for (i = 1; i < counter; i++)
		{
			temp = temp->next;
			if (min->element > temp->element)
			{
				min = temp;
			}
			
		}
		t = fsort->element;
		fsort->element = min->element;
		min->element = t;
		counter--;
		fsort = fsort->next;
		sortindex++;
		temp = fsort;
		min = fsort;
	}
}

// �������� ����� � �������
int LineSearh(int element, vector<int>& vectorenter)
{
	int k = 0;
	int i;
	List* slider = new List;
	slider = Head;
	for (i = 0; i < NumElem; i++)
	{
		if (slider->element == element)
		{
			k++;
			vectorenter.push_back(NumElem - (NumElem - i - 1));
		}
		slider = slider->next;
	}
	return(k);
}