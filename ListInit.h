#pragma once
struct List
{
	int element;
	List* previous;
	List* next;
};
extern List* Tail;
extern List* Head;
extern int NumElem;
void Init(int startQuantity);