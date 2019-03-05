#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void fmao(int*a, int s)
{

	for (int i = 0; i < s - 1; i++)
	{
		int work = 1;
		for (int j = 0; j <s-i-1; j++)
		{
			int m;
			if (a[j - 1] > a[j])

			{
				m = a[j - 1];
				a[j - 1] = a[j];
				a[j] = m;
				work = 0;
			}
		}
		if (work) break;
	}

}
int main()
{
	int a[10], i;
	srand(int(time(0)));
	for (i = 0; i < 10; i++)
		a[i] = rand() % 100;
	cout << "origianl line:" << "   ";
	for (i = 1; i < 11; i++)
	{
		cout << a[i-1] << " ";
		if (i % 5 == 0)
			cout << endl<<"           ";
	}
	fmao(a, 10);
	cout << "order:" << "  ";
	for (i = 1; i < 11; i++)
	{
		cout << a[i-1] << "  ";
		if (i % 5 == 0)
			cout << endl<<"          ";
	}
	system("pause");



}