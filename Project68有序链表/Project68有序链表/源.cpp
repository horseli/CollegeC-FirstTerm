#include<iostream>
using namespace std;
struct List
{
	int date;
	List *next;
};
//�����ݲ�����������
void Insert(List *&head, int num)
{
	List *s, *q, *p;
	s = new List;
	s->date = num;
	s->next = NULL;
	if (head == NULL)    //����գ�����һ���ڵ������
	{
		head = s;
		return;              //Ϊʲô�˴��������return�����������ȷ������
	}
 if (head->date > s->date)   //����������С�������ͷ
	{
		 s->next = head;
		head = s;
		
	}
	
		for (q = head, p = head->next; p; q = p, p = p->next)    ///��������
		{
			if (p->date > s->date)
			{
				q->next = s;
				s->next = p;
				return;
			}
		}

		q->next = s;    //����������󣬲��˱�β
		return;
}
//�����������
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
	 while (num)//������������
	 {
		 Insert(head, num);
			 cin >> num;
	 }
	ShowList(head);
	system("pause");
}