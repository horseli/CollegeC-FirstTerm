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
	int all;//总位数
	int point;//整数位数
	numb*next;
	numb*last;
};
numb*CreateList(string);
numb*CreateList(int*);
numb*Add(numb*,numb*);
numb*Minus(numb*, numb*);
numb*Multiply(numb*, numb*);
numb*Divide(numb*, numb*,int);
numb*FullPoint(numb*, int);//扩展为相同位数
numb*FindLast(numb*);
int FindAll(numb*);
numb*MultiplySingle(numb*, int);
numb*FullInteger(numb*a, int len);
numb*AllAddMiinus(numb*a, numb*b);//所有可能的加减法
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
	//正负
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
	//位数
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
//补充为相同位数的小数
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
//除法时改变被除数为指定长度 len>0 多加一位
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
	//小数位数长度
	int pointlen_a = a->all - a->point;
	int pointlen_b = b->all - b->point;
	if (pointlen_a > pointlen_b)
		FullPoint(b, pointlen_a);
	else if (pointlen_a < pointlen_b)
		FullPoint(a, pointlen_b);
	numb result;//结果
	numb*p,*q;
	numb*alast = FindLast(a);
	numb*blast = FindLast(b);
	p = new numb;
	int re = alast->value + blast->value;
	int flag = 0;//进位标识符
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
		if (flag)//进位
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
		//指针前移;
		alast = alast->last;
		blast = blast->last;
	}
	//位数相同 如有进位
	if (a->point == b->point) {
		if (flag) {
			q->value = 1;
			q->next = p;
			p->last = q;
			p = q;
		}
	}
	//未加完的整数部分
	else if (a->point > b->point) {
		while (alast) {
			q = new numb;
			re = alast->value;
			if (flag)//进位
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
			//指针前移
			alast = alast->last;
		}
	}
	else {
		while (blast) {
			q = new numb;
			re = blast->value;
			if (flag)//进位
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
			//指针前移
			blast = blast->last;
		}
	}
	result.next = q;
	q->last = &result;
	//更新位数
	result.all =  FindAll(&result);
	int po =(a->all- a->point) >(b->all- b->point) ? (a->all - a->point) : (b->all - b->point);//小数位数以长的那一个为准
	result.point = result.all-po ;//整数位数更新
	delete p;
	delete q;
	return &result;
}
/*a-b且大于a>b*/
numb*Minus(numb*a, numb*b) {
	//小数位数长度
	int pointlen_a = a->all - a->point;
	int pointlen_b = b->all - b->point;
	//补全
	if (pointlen_a > pointlen_b)
		FullPoint(b, pointlen_a);
	else if (pointlen_a < pointlen_b)
		FullPoint(a, pointlen_b);
	numb result;//结果
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
		if (flag)//进位
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
		//指针前移
		alast = alast->last;
		blast =  blast->last;
	}
	//未减完的整数部分
	if (a->point > b->point) {
		while (alast) {
			q = new numb;
			re = alast->value;
			if (flag)//进位
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
			//指针前移
			alast = alast->last;
		}
	}
	else {
		while (blast) {
			q = new numb;
			re = blast->value;
			if (flag)//进位
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
			//指针前移
			blast = blast->last;
		}
	}
	result.next = q;
	q->last = &result;
	result.all = FindAll(&result);
	int po = (a->all - a->point) >(b->all - b->point) ? (a->all - a->point) : (b->all - b->point);//小数位数以长的那一个为准
	result.point = result.all - po;//整数位数更新
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
//a的位数较多
numb*Multiply(numb*a, numb*b) {
	//记录下小数点的位置和正负，变为正整数运算
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
			numb*yextend = new numb;//最后一位一次后移一位
			yextend->value = 0;
			ylast->next = yextend;
			yextend->last = ylast;
			ylast = yextend;
		}
		x = *Add(&x, &y);
		//指针前移
		blast = blast->last;
	}
	x.symbol = aall == '-'&&ball == '+' || aall == '+'&&ball == '-' ? '-' : '+';
	x.point = a->all-a->point + b->all-b->point;
	x.all = FindAll(&x);
	return &x;
}
//保留小数点后位数为c  a/b
//numb*Divide(numb*a, numb*b,int c) {
//	int len = c + b->all - a->all;//多出的位数，以防万一多加一位
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
