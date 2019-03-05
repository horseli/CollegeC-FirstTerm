#include<iostream>
using namespace std;
struct List
{
	int date;
	List *next;
};
void DeleteList(List *&head, int key)
{
	List *q, *p;
	if (head->date == key)
	{
		p = head;
		head = head->next;
		delete p;
		p = NULL;
		return;
	}
	for (q = head, p = head->next; p; q = p, p = p->next)
	{
		if (p->date == key)
		{
			q->next = p->next;
			delete p;
			p = NULL;//хщрвремЭ
		}
	}
	return;
}
