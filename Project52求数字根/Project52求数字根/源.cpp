#include<iostream>
#include<cmath>
using namespace std;
int gen(int a);
int main()
{
	cout << "number: ";
	int a;
	cin >> a;
	cout <<"sum"<< gen(a) << endl;
}
int gen(int a)
{
	int i;
	for( i=1;a/pow(10,i)!=0;i++)
	int*p = new int[i];
	for (int k = 0; k < i; k++)
	{
		p[k] = a / pow(10, i - 1 - k);
		a = a% pow(10, i - k - 1);
	}
	int sum,j;
	for (sum = 0, j = 0; j < i; j++)
	{
		sum += p[j];
	}
	delete[]p;
	p = NULL;
	return sum;
}