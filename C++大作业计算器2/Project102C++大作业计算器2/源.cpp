#include<iostream>
//#include<cmath>
#include<string>
#define POSITIVE 0;
#define NEGTIVE -1;
#define DEFAULT 1;
#define true 1;
#define false -1;
#define equal 0;
using namespace std;
struct numb {
	int symbol = DEFAULT;
	int value;
	int all;//��λ��
	int point;//����λ��
	numb*next;
	numb*last;
};

numb*CreateList(string);//����
numb*Add(numb*, numb*);//�ӷ�
numb*Minus(numb*, numb*);//����
numb*Multiply(numb*, numb*);//�˷�
numb*Divide(numb*, numb*, int);//����
numb*FullPoint(numb*, int);//��չΪ��ͬС��λ��
numb*FindLast(numb*);//�ҵ�����β��
int FindAll(numb*);//�����ܳ���
numb*MultiplySingle(numb*, int);//���������
numb*FullInteger(numb*a, int len);
int ShortInteger(numb * a);
int compare(numb*, numb*);
void InsertLast(numb * a, int value);
void InsertFirst(numb * a, int value);
numb*AllAddMinus(numb*a, numb*b);//���п��ܵļӼ���
void Print(numb*);
void Print(numb*, int);
void Print(numb*a, int c) {
	if (a->symbol == -1)
		cout << '-';
	numb*p = a->next;
	int aall = a->all;
	int apoint = a->point;
	int po = aall - apoint;	
	int n = 0;
	while (a->point != 1 && p->value == 0) {
		p = p->next;
		a->point--;
		a->all--;
	}
	int flag = 0;
	for (int i = 1; 3 * i < a->point; i++) {
		if (3 * i + 1 == a->point) {
			flag = 1;
			break;
		}
		else if (3 * i + 2 == a->point) {
			flag = 2;
			break;
		}
		else if (3 * i + 3 == a->point) {
			flag = 3;
			break;
		}
	}
	int records = 0;
	while (n<=c+a->point) {
		if (n == 0)
		{
			for (int i = 0; i < flag; i++) {
				cout << p->value;
				p = p->next;
				n++;
			}
			if (flag)
				cout << ',';
		}
		if (a->point == n&&c!=0)
			cout << '.';
		else if (p == NULL) {
			cout << '0';
		}
		else
		{
			cout << p->value;
			p = p->next;
		}
		records++;
		int recordint = records / 3;
		if (records == 3 * recordint&&a->point>n+1 )
			cout << ',';
		n++;
	}
}
void Print(numb*a) {
	numb*p = a->next;
	int n = 0;
	while (a->point!=1&&p->value == 0) {
		p = p->next;
	}
	while (p!=NULL) {
		if (a->point == n&&a->point!=a->all)
			cout << '.';
		else
		{
			cout << p->value;
			p = p->next;
		}
		n++;
	}
	delete p;
	p = NULL;
}
numb*CreateList(string s) {
	int len = s.length();
	numb head, *p, *q;
	//����
	int symbol;
	if (s[0] == '-' || s[0] == '+')
	{
		
		if (s[0] == '-')
		{
			head.symbol = NEGTIVE;
		}
		else head.symbol = POSITIVE;
		for (int i = 0; i < len - 1; i++)
			s[i] = s[i + 1];
		len--;
	}
	else head.symbol = POSITIVE;
	head.last = NULL;//ǰΪNULL
	p = new numb;
	p->value = (int)s[0]-48;
	head.next = p;
	//p->last = &head;
	p->last = NULL;
	q = new numb;
	p->next = NULL;
	q = p;
	int flag = 0;//��
	int f = 0;
	for (int i = 1; i < len; i++) {
		if (s[i] == ',')
			f++;
		if (s[i] == '.'||s[i]==',') {
			continue;
		}
		else {
			q = new numb;
			q->next = NULL;
			q->value = (int)s[i]-48;
			q->last = p;
			p->next = q;
			p = q;
		}
	}
	/*delete q;
	q = NULL;
	delete p;
	p = NULL;*/
	//λ��
	
	head.all = len;
	head.point = len;
	int poin = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '.') {
			len = len - 1;
			break;
		}
		else poin++;
	}
	head.point = poin - f;
	head.all = len - f;
	return &head;
}
//����Ϊ��ͬλ����С��
numb*FindLast(numb*a) {
	numb*l=a->next;
	while (l->next) {
		l = l->next;
	}
	return l;
}
numb*FullPoint(numb*h, int len) {
	numb*l = h;
	while (l->next)
		l = l->next;
	int lenx = h->all - h->point;
	numb*t;
	t = new numb;
	t->value = 0;
	t->next = NULL;
	for (int i = 0; i < len - lenx; i++) {
		l->next = t;
		t->last = l;
		l = t;
		t = new numb;
		t->value = 0;
		t->next = NULL;
		h->all++;
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
		p->next = NULL;
		l = p;
		//delete p;
	}
	return a;

}
int ShortInteger(numb*a) {
	numb*p = a->next;
	int i = 0;
	while (p->next&&p->value == 0) {
		i++;
		p = p->next;
		a->all--;
		a->point--;
	}
	a->next = p;
	p->last = NULL;
	return i;
}
numb*Add(numb*a, numb*b) {
	//С��λ������
	int pointlen_a = a->all - a->point;
	int pointlen_b = b->all - b->point;
	if (pointlen_a > pointlen_b)
		b=FullPoint(b, pointlen_a);
	else if (pointlen_a < pointlen_b)
		a=FullPoint(a, pointlen_b);
	numb result;//���
	numb*p, *q;
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
	p->next = NULL;
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
		q->next = p;
		p->last = q;
		p = q;
		//ָ��ǰ��;
		alast = alast->last;
		blast = blast->last;
	}
	//λ����ͬ ���н�λ
	if (a->point == b->point) {
		if (flag) {
			q = new numb;
			q->value = 1;
			q->next = p;
			p->last = q;
			p = q;
			//p->last = NULL;
			flag = 0;
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
	//���һλ��λ
	/*if (flag) {
		q = new numb;
		re = 1;
		flag = 0;
		q->value = re;
		q->next = p;
		p->last = q;
		p = q;
	}*/
	result.next = q;
	q->last = NULL;
	//����λ��
	result.all = FindAll(&result);
	int po = (a->all - a->point) >(b->all - b->point) ? (a->all - a->point) : (b->all - b->point);//С��λ���Գ�����һ��Ϊ׼
	result.point = result.all - po;//����λ������
	/*delete p;
	p = NULL;*/
	//delete q;
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
	p->next = NULL;
	
	int re = alast->value - blast->value;
	int flag = 0;
	if (re < 0) {
		re += 10;
		flag = 1;
	}
	p->value = re;
	q = new numb;
	q = p;
	alast = alast->last;
	blast = blast->last;
	while (alast&&blast) {
		q = new numb;
		q->next = NULL;
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
		blast = blast->last;
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
	int po = (a->all - a->point) >(b->all - b->point) ? (a->all - a->point) : (b->all - b->point);//С��λ���Գ�����һ��Ϊ׼
	//��������λΪ���λ��
		while (q&&q->value == 0&&q->next)
			q = q->next;
	result.next = q;
	//0.003
	while (q&&FindAll(&result) <= po&&q->next) {
		q = q->last;
		result.next = q;
	}
	q->last = NULL;
	result.all = FindAll(&result);
	
	result.point = result.all - po;//����λ������
	/*delete p;
	delete q;*/
	return &result;
}
numb*AllAddMinus(numb*a, numb*b) {
	int pos = POSITIVE;
	int neg = NEGTIVE;
	numb result;
	if ((a->symbol ==pos )&&b->symbol == pos) {
		result = *Add(a, b);
		return &result;
	}
	if ((a->symbol == pos) && b->symbol == neg) {
		//a>=b
		if (compare(a, b) > -1) {
			result = *Minus(a, b);
			return &result;
		}
		else {
			result = *Minus(b, a);
			result.symbol = neg;
			return &result;
		}
	}
	//a��b��
	if (compare(b, a) > -1) {
		result = *Minus(b, a);
		return &result;
	}
	else {//a��
		result = *Minus(a, b);
		result.symbol = neg;
		return &result;
	}
}
numb*MultiplySingle(numb*a, int n) {
	numb h;
	numb*b = new numb;
	
	b->all = a->all;
	b->point = a->point;
	numb*ab = a->next;
	numb*p, *q;
	p = new numb;
	b->next = p;
	p->value = ab->value;
	p->next = NULL;
	p->last = NULL;
	q = p;
	ab = ab->next;
	while (ab) {
		q = new numb;
		q->value = ab->value;
		q->next = NULL;
		q->last = p;
		p->next = q;
		p = q;
		ab = ab->next;
	}
	/*delete ab;
	ab = NULL;*/
	h = *b;
	if (n == 0) {
		numb*t = h.next;
		while (t) {
			t->value = 0;
			t = t->next;
		}
		delete b;
		b = NULL;
		return &h;
	}
	for (int i = 0; i < n - 1; i++) {
		h = *Add(b, &h);
	}
	delete b;
	b = NULL;
	return &h;
}
int FindAll(numb*a) {
	numb*h = a;
	int n = 0;
	while (h->next) {
		n++;
		h = h->next;
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
	b->point = ball;
	int aall = a->all;
	int apoint = a->point;
	int asymbol = a->symbol;
	a->symbol = POSITIVE;
	a->point = aall;
	int extraA = 0;
	if(a->point==1&&a->next->value==0){
	 extraA = ShortInteger(a);//ȥ��ǰ���0
	}
	int realA = FindAll(a);//ʵ������
	int extraB = 0;
	if (b->point == 1 && b->next->value == 0) {
		extraB = ShortInteger(b);//ȥ��ǰ���0
	}
	int realB = FindAll(b);
	int pon = aall - apoint + ball - bpoint;//С��λ��
	
	int extra0 = pon-realA-realB;
	if (extra0 < 0)
		extra0 = 0;
	numb x, y;
	x.point = 1;
	x.all = extra0 + 1;
	numb*blast;
	blast = FindLast(b);
	x = *MultiplySingle(a, blast->value);
	int locat = 0;
	blast = blast->last;
	while (blast) {
		locat++;
		y = *MultiplySingle(a, blast->value);
		numb*ylast = FindLast(&y);
		for (int i = 0; i < locat; i++) {
			numb*yextend = new numb;//���һλһ��ǰ��һλ
			yextend->next = NULL;
			yextend->value = 0;
			ylast->next = yextend;
			yextend->last = ylast;
			ylast = yextend;
			y.all++;
			y.point++;
		}
		x = *Add(&x, &y);
		//ָ��ǰ��
		blast = blast->last;
	}
	x.symbol = (asymbol == -1 && bsymbol == 0) || (asymbol == 0 && bsymbol == -1) ? -1 : 0;
	x.all = FindAll(&x);
	x.point = x.all-(aall - apoint + ball - bpoint);
	ShortInteger(&x);
	
	numb*p;
	while (x.point<=0) {
		x.point++;
		x.all = 1 + x.all;
		p = new numb;
		p->value = 0;
		p->next = x.next;
		p->last = NULL;
		x.next = p;
		//x.all++;
	}
	return &x;
}
int compare(numb*a, numb*b) {
	//λ�����
	if (a->point > b->point)
		return true;
	if (a->point < b->point)
		return false;
	numb*ha = a->next;
	numb*hb = b->next;
	//��λ���
	while (ha&&hb&&ha->value==hb->value) {
		ha = ha->next;
		hb = hb->next;
	}
	if (ha&&hb&&ha->value > hb->value)
		return true;
	 if (ha&&hb&&ha->value < hb->value)
		return false;
	 return equal;
}
int FindLocat(numb*p) {
	numb*l = p;
	int locat = 0;
	while (l) {
		l = l->last;
		locat++;
	}
	return locat;
}
//���
void InsertLast(numb*a, int value) {
	numb*r = new numb;
	r->next = NULL;
	r->value = value;
	numb*l = FindLast(a);
	l->next = r;
	r->last = l;
}
//ǰ��
void InsertFirst(numb*a, int value=0) {
	numb*r = new numb;
	r->last = NULL;
	r->value = value;
	r->next = a->next;
	a->next = r;
	
}
//����С�����λ��Ϊc  a/b
numb*Divide(numb*a, numb*b,int c) {
	int recordBig = 0;
	if (compare(a, b) == -1) {
		recordBig = 1;
	}
	int ball = b->all;
	int bpoint = b->point;
	int bsymbol = b->symbol;
	b->symbol = POSITIVE;
	b->point = ball;
	int aall = a->all;
	int apoint = a->point;
	int asymbol = a->symbol;
	int extraA = ShortInteger(a);//ȥ��ǰ���0
	int realA = FindAll(a);//ʵ������
	int extraB = ShortInteger(b);//ȥ��ǰ���0
	int realB = FindAll(b);
	a->symbol = POSITIVE;
	a->point = aall;
	numb*p, *q, *r;
	numb t1, result;//t1Ϊ������
	result.next = NULL;
	int len = c - (aall - apoint - ball + bpoint) + 300;//�����λ�����Է���һ���һλ
													  //int po = a->all + b->all - a->point - b->point;//
	if (len > 0) {
		a = FullInteger(a, len);
	}

	//Խ��С����ı���������ʵ��λ��
	a->point = aall - (aall - apoint - (ball - bpoint))-extraA;//��������λ��
	int po = aall - apoint - (ball - bpoint);//С������λ��
	p = new numb;
	p = a->next;
	q = new numb;
	q->next = NULL;
	q->value = p->value;
	t1.next = q;
	q->last = NULL;
	r = q;
	t1.all = t1.point = 1;
	int extra0 = 0;
	//���Ϊ��С�����
	int recordExtra = 0;
	int recordP = 0;
	if (recordBig) {
		int pon = aall - apoint - ball + bpoint;
		extra0= pon - realA;
		if (extra0 < 0)
		{
			extra0 = 0;
			recordP = 1;
		}
		result.point = 1;
		result.all = extra0+1;
		recordExtra = 1;
	}
	else {
		
		result.all = result.point = 0;
	}
	int count = 0;//ѭ������
	//�������� ������С��λ���ﵽ
	while (result.all-result.point<c) {
		count++;
		numb m;//����
		if (count == 1) {
			while (compare(b, &t1) == 1 &&p&&(result.all - result.point<c)) {
				p = p->next;
				r = new numb;
				r->next = NULL;
				r->value = p->value;
				q = FindLast(&t1);//�ҵ����
				q->next = r;
				r->last = q;
				q = r;
				t1.all++;
				t1.point++;
				ShortInteger(&t1);
				if (a->point == 1)
				{
					extra0++;
					result.all++;
				}
			}
		}
		else {
			int record_0=0;
			while (compare(b, &t1)==1&&p->next && (result.all - result.point)<c) {

				p = p->next;
				r = new numb;
				r->next = NULL;
				r->value = p->value;
				q = FindLast(&t1);//�ҵ����
				q->next = r;
				r->last = q;
				q = r;
				t1.all++;
				t1.point++;
				ShortInteger(&t1);
				int locatt = 0;
				numb*ls = p;
				while (ls)
				{
					locatt++;
					ls = ls->last;
				}
				if (compare(&t1,b)==-1) {
					InsertLast(&result,0) ;
					result.all++;
					if (locatt <= a->point)
						result.point++;
					ShortInteger(&t1);
				}
				record_0++;
			}
		}
		//�������ȼ���Сʱ b>t1
		//while (compare(b, &t1)==1 ) {
		//	p = p->next;
		//	r = new numb;
		//	r->next = NULL;
		//	r->value = p->value;
		//	q = FindLast(&t1);//�ҵ����
		//	q->next = r;
		//	r->last = q;
		//	q = r;
		//	t1.all++;
		//	t1.point++;
		//	ShortInteger(&t1);
		//}
		int re = 0;
		if (p->next && (result.all - result.point)<c) {
			int i = 1;
			//m = *MultiplySingle(b, 1);
			//i<t1<i+1
			numb c1 = *MultiplySingle(b, i);
			numb c2 = *MultiplySingle(b, i + 1);
			//compare(&c2, &t1);
			while (compare(&t1, &c1) == -1 || compare(&c2, &t1) < 1) {
				i++;
				c1 = *MultiplySingle(b, i);
				c2 = *MultiplySingle(b, i + 1);
			}
			t1 = *Minus(&t1, &c1);
			re = i;
		}
		int locat=0;
		numb*l = p;
		while (l)
		{
			locat++;
			l = l->last;
		}
		if (count == 1&&(result.all-result.point<c)) {
			r = new numb;
			r->next = NULL;
			r->value = re;
			r->last = NULL;
			q = r;
			result.next = r;
			result.all++;
			if (locat <= a->point)
				result.point++;
		}
		else if((result.all - result.point)<c){
			if(p->next && (FindAll(&result) - result.point)<c)
			InsertLast(&result, re);
			result.all++;
			if (locat <= a->point)
				result.point++;
		}
	}
	if (recordExtra) {
		if (extra0 > 0) {
		p = new numb;
		p->value = 0;
		p->next = result.next;
		p->last = NULL;
		result.next = p;
		//result.all++;
		if (recordP)
			extra0--;
		for (int i = 1; i < extra0+1; i++) {
			p = new numb;
			p->value = 0;
			p->next = result.next;
			p->last = NULL;
			result.next = p;
		//result.all++;
		}
		}
	}
	result.symbol = (asymbol == -1&&bsymbol == 0) || (asymbol == 0&&bsymbol == -1) ? -1 : 0;
	return &result;
}
int main() {
	 cout << "*****������ʾ����������ʽ�ͱ�����С��λ��*****\n��ʽ��-768.798798/(-2387.79)��0.0098*78.6783��\n#ʾ����\n#����������ʽ��0.06567566543/(-635457.987654)\n#������С��λ����40\n#�����0.0000000000103351703347790301690779036020" << endl<<endl;
	while (1) {
		string all;
		string a = "", b = "";
		int flag = 0;
		
		cout << "����������ʽ��";
		cin >> all;

		a += all[0];
		char ch;
		int i;
		for (i = 1; i < all.length(); i++) {
			if (all[i] == '+' || all[i] == '-' || all[i] == '/' || all[i] == '*') {
				ch = all[i];
				break;
			}
			a += all[i];
		}
		for (; i < all.length(); i++) {
			if (all[i] == '(' || all[i] == ')' || all[i] == '*' || all[i] == '/')
				continue;
			if (all[i] + all[i + 1] == -180 || all[i] + all[i + 1] == -181 || all[i] + all[i - 1] == -180 || all[i] + all[i - 1] == -181)
				continue;
			b += all[i];
		}
		//cout << a << endl;
		//cout << b << endl;
		//a = "2.3456";
		//b = "12";
		//int c = 10;
		////cout << a<<endl;
		numb aa = *CreateList(a);
		numb bb = *CreateList(b);
		numb result;
		Print(&aa);
		Print(&bb);
		int c = 0;
		cout << "������С��λ����";
		cin >> c;
		switch (ch) {
		case'-':
		case'+': {result = *AllAddMinus(&aa, &bb);
			break; }
		case'*':result =*Multiply(&aa, &bb);
			break;
		case'/':result = *Divide(&aa, &bb,c );
			break;
		}
		//result = *Multiply(&aa, &bb);
		cout << "���:";
		Print(&result, c);
		cout << "\n\n";
		//Print(&aa);
		//cout << endl;
		//Print(&bb);
		//cout << endl;
		////numb r = *Add(&aa, &bb);
		////Print(&aa);
		////numb r = *Minus(&bb, &aa);
		////
		////numb r=*MultiplySingle(&aa,5);
		////numb r = *Multiply(&aa, &bb);
		//numb r = *Divide(&aa, &bb,c );
		//Print(&r);
		/*string s;
		cin >> s;
		cout << s[2];*/
	}
	system("pause");
}
