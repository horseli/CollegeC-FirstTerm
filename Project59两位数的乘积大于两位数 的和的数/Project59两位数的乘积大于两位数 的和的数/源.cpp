#include<iostream>
using namespace std;
int main()
{
	int i, j, k, t;
	for (i = 10,j=0; i < 100; i++)
	{
		k = i / 10;
		t = i % 10;
		if (k*t > k + t)
		{
			cout << i << " ";
			j++;
		}
		if (j % 10 ==0)
			cout << endl;
	}
	system("pause");
}