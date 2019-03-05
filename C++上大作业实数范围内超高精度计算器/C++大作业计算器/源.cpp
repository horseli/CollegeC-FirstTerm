#include<iostream>
#include<cmath>
#include<string>
#define POSITIVE 0;
#define NEGTIVE -1;
#define DEFAULT 1;
using namespace std;
struct numb {
	int symbol = DEFAULT;
	int value;
	int all;//��λ��
	int point;//����λ��
	numb*next;
	numb*last;
};
numb*CreateList(string);
numb*CreateList(int*);
numb*Add(numb*,numb*);
numb*Minus(numb*, numb*);
numb*Multiply(numb*, numb*);
numb*Divide(numb*, numb*,int);
numb*FullPoint(numb*, int);//��չΪ��ͬλ��
numb*FindLast(numb*);
int FindAll(numb*);
numb*MultiplySingle(numb*, int);
numb*FullInteger(numb*a, int len);
numb*AllAddMiinus(numb*a, numb*b);//���п��ܵļӼ���
void Print(numb*);
void Print(numb*a) {
	numb*p = a->next;
	int n = 0;
	while (p) {
		if (a->point == n)
			cout << '.';
		else
		{
			cout << p->value;
			p = p->next;
		}
		n++;
	}
	delete p;
}
numb*CreateList(string s) {
	int len = s.length();
	numb head, *p, *q;
	//����
	int symbol;
	if (s[0] == '-'||s[0]=='+')
	{
		for (int i = 0; i < len - 1; i++)
			s[i] = s[i + 1];
		if (s[0] == '-')
		{
			head.symbol = NEGTIVE;
		}
		else head.symbol = POSITIVE;
		len--;
	}
	else head.symbol = POSITIVE;
	p = new numb;
	p->value = (int)s[0];
	head.next = p;
	p->last = &head;
	q = new numb;
	q = p;
	for (int i = 1; i < len; i++) {
		if (s[i] == '.') {
			continue;
		}
		else {
			q = new numb;
			q->value = (int)s[i];
			q->last = p;
			p->next = q;
			p = q;
		}
	}
	delete q;
	delete p;
	//λ��
	head.all = len - 1;
	int poin=0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '.') {
			head.point = poin;
			break;
		}
		else poin++;
	}
	return &head;
}
//����Ϊ��ͬλ����С��
numb*FullPoint(numb*h, int len) {
	numb*l = h;
	while (l->next)
		l = l->next;
	int lenx = h->all-h->point;
	numb*t;
	t = new numb;
	t->value = 0;
	for (int i = 0; i < len - lenx; i++) {
		l->next = t;
		t->last = l;
		l = t;
		t = new numb;
		t->value = 0;
	}
	delete t;
	return h;
}
//����ʱ�ı䱻����Ϊָ������ len>0 ���һλ
numb*FullInteger(numb*a, int len) {
	numb*l = FindLast(a);
	for (int i = 0; i < len; i++) {
		numb*p = new numb;
		p->value = 0;
		l->next = p;
		p->last = l;
		l = p;
		delete p;
	}
	return a;

}
numb*Add(numb*a, numb*b) {
	//С��λ������
	int pointlen_a = a->all - a->point;
	int pointlen_b = b->all - b->point;
	if (pointlen_a > pointlen_b)
		FullPoint(b, pointlen_a);
	else if (pointlen_a < pointlen_b)
		FullPoint(a, pointlen_b);
	numb result;//���
	numb*p,*q;
	numb*alast = FindLast(a);
	numb*blast = FindLast(b);
	p = new numb;
	int re = alast->value + blast->value;
	int flag = 0;//��λ��ʶ��
	if (re >= 10) {
		re -= 10;
		flag = 1;
	}
	p->value = re;
	q = new numb;
	q = p;
	alast = alast->last;
	blast = blast->last;
	while (alast&&blast) {
		q = new numb;
		re = alast->value + blast->value;
		if (flag)//��λ
			re++;
		flag = 0;
		if (re >= 10) {
			re -= 10;
			flag = 1;
		}
		q->value = re;
		q -> next = p;
		p->last = q;
		p=q;
		//ָ��ǰ��;
		alast = alast->last;
		blast = blast->last;
	}
	//λ����ͬ ���н�λ
	if (a->point == b->point) {
		if (flag) {
			q->value = 1;
			q->next = p;
			p->last = q;
			p = q;
		}
	}
	//δ�������������
	else if (a->point > b->point) {
		while (alast) {
			q = new numb;
			re = alast->value;
			if (flag)//��λ
				re++;
			flag = 0;
			if (re >= 10) {
				re -= 10;
				flag = 1;
			}
			q->value = re;
			q->next = p;
			p->last = q;
			p = q;
			//ָ��ǰ��
			alast = alast->last;
		}
	}
	else {
		while (blast) {
			q = new numb;
			re = blast->value;
			if (flag)//��λ
				re++;
			flag = 0;
			if (re >= 10) {
				re -= 10;
				flag = 1;
			}
			q->value = re;
			q->next = p;
			p->last = q;
			p = q;
			//ָ��ǰ��
			blast = blast->last;
		}
	}
	result.next = q;
	q->last = &result;
	//����λ��
	result.all =  FindAll(&result);
	int po =(a->all- a->point) >(b->all- b->point) ? (a->all - a->point) : (b->all - b->point);//С��λ���Գ�����һ��Ϊ׼
	result.point = result.all-po ;//����λ������
	delete p;
	delete q;
	return &result;
}
/*a-b�Ҵ���a>b*/
numb*Minus(numb*a, numb*b) {
	//С��λ������
	int pointlen_a = a->all - a->point;
	int pointlen_b = b->all - b->point;
	//��ȫ
	if (pointlen_a > pointlen_b)
		FullPoint(b, pointlen_a);
	else if (pointlen_a < pointlen_b)
		FullPoint(a, pointlen_b);
	numb result;//���
	numb*p, *q;
	numb*alast = FindLast(a);
	numb*blast = FindLast(b);
	p = new numb;
	int re = alast->value - blast->value;
	int flag = 0;
	if (re < 0) {
		re += 10;
		flag = 1;
	}
	p->value = re;
	q = new numb;
	q = p;
	while (alast&&blast) {
		q = new numb;
		re = alast->value - blast->value;
		if (flag)//��λ
			re--;
		flag = 0;
		if (re < 0) {
			re += 10;
			flag = 1;
		}
		q->value = re;
		q->next = p;
		p->last = q;
		p = q;
		//ָ��ǰ��
		alast = alast->last;
		blast =  blast->last;
	}
	//δ�������������
	if (a->point > b->point) {
		while (alast) {
			q = new numb;
			re = alast->value;
			if (flag)//��λ
				re--;
			flag = 0;
			if (re<0) {
				re += 10;
				flag = 1;
			}
			q->value = re;
			q->next = p;
			p->last = q;
			p = q;
			//ָ��ǰ��
			alast = alast->last;
		}
	}
	else {
		while (blast) {
			q = new numb;
			re = blast->value;
			if (flag)//��λ
				re--;
			flag = 0;
			if (re<0) {
				re += 10;
				flag = 1;
			}
			q->value = re;
			q->next = p;
			p->last = q;
			p = q;
			//ָ��ǰ��
			blast = blast->last;
		}
	}
	result.next = q;
	q->last = &result;
	result.all = FindAll(&result);
	int po = (a->all - a->point) >(b->all - b->point) ? (a->all - a->point) : (b->all - b->point);//С��λ���Գ�����һ��Ϊ׼
	result.point = result.all - po;//����λ������
	delete p;
	delete q;
	return &result;
}
numb*MultiplySingle(numb*a, int n) {
	numb h;
	for (int i = 0; i < n-1; i++) {
		h = *Add(a, a);
	}
	return &h;
}
int FindAll(numb*a) {
	numb*h = a;
	int n = 0;
	while (h->next) {
		n++;
	}
	return n;
}
//a��λ���϶�
numb*Multiply(numb*a, numb*b) {
	//��¼��С�����λ�ú���������Ϊ����������
	int ball = b->all;
	int bpoint = b->point;
	int bsymbol = b->symbol;
	b->symbol = POSITIVE;
	b->point = 0;
	int aall = b->all;
	int apoint = b->point;
	int asymbol = b->symbol;
	a->symbol = POSITIVE;
	a->point = 0;
	numb x, y;
	numb*blast;
	blast = FindLast(b);
	x = *MultiplySingle(a, blast->value);
	int locat = 0;
	while (blast->last) {
		y = *MultiplySingle(a, blast->last->value);
		numb*ylast = FindLast(&y);
		for (int i = 0; i < locat; i++) {
			numb*yextend = new numb;//���һλһ�κ���һλ
			yextend->value = 0;
			ylast->next = yextend;
			yextend->last = ylast;
			ylast = yextend;
		}
		x = *Add(&x, &y);
		//ָ��ǰ��
		blast = blast->last;
	}
	x.symbol = aall == '-'&&ball == '+' || aall == '+'&&ball == '-' ? '-' : '+';
	x.point = a->all-a->point + b->all-b->point;
	x.all = FindAll(&x);
	return &x;
}
//����С�����λ��Ϊc  a/b
//numb*Divide(numb*a, numb*b,int c) {
//	int len = c + b->all - a->all;//�����λ�����Է���һ���һλ
//	//int po = a->all + b->all - a->point - b->point;//
//	if (len > 0) {
//		a = FullInteger(a, len);
//	}
//	numb*p, *q;
//
//	return p;
//}
int main() {
	string a,b;
	a = '8';
	b = '9';
	numb aa = *CreateList(a);
	numb bb = *CreateList(b);
	numb r = *Add(&aa, &bb);
	Print(&r);
	/*string s;
	cin >> s;
	cout << s[2];*/
	system("pause");
}
