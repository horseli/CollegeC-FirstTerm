#include<iostream>
using namespace std;
struct List
{
	int date;
	List *next;
};
//把数据插入有序链表
void Insert(List *&head, int num)
{
	List *s, *q, *p;
	s = new List;
	s->date = num;
	s->next = NULL;
	if (head == NULL)    //若表空，建立一个节点的链表
	{
		head = s;
		return;              //为什么此处必须加上return否则输出不正确？？？
	}
 if (head->date > s->date)   //被插数据最小，插入表头
	{
		 s->next = head;
		head = s;
		
	}
	
		for (q = head, p = head->next; p; q = p, p = p->next)    ///搜索插入
		{
			if (p->date > s->date)
			{
				q->next = s;
				s->next = p;
				return;
			}
		}

		q->next = s;    //被插数据最大，插人表尾
		return;
}
//输出链表数据
void ShowList(List *head)
{
	while(head)
	{
		cout << head->date<<'\t';
		head = head->next;
	}
}
int main()
{
	List *head=NULL;
	int num;
	cin >> num;
	 while (num)//建立有序链表
	 {
		 Insert(head, num);
			 cin >> num;
	 }
	ShowList(head);
	system("pause");
}