#include<iostream>
#include<iomanip>
using namespace std;
void sort(int*a, int num)
{
	int i, j, t,tept;
	for (i = 0; i < num-1; i++)
	{
		for (j =i +1, t = i; j < num ; j++)
		{
			if (a[t] > a[j]) t = j;

		}
		if (t != i)
		{
			tept = a[t];
			a[t] = a[i];
			a[i] = tept;//cܳ�Ĳ���ȫ��  ��ס���κ���Ҫ��{ }�ĵط�����
		}
	}
	for (i = 0; i < num; i++)
	{
		cout << a[i] << setw(4);
		if ((i+1) % 5 == 0) cout << endl;
	}

}
int main()
{
	int a[] = { 2,53,6,3,4,7,5 };
 sort(a, sizeof(a) / sizeof(int)) ;
	system("pause");
}