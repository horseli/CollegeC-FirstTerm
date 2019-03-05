#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cout << "create matrix:" << endl;
		int**a = new int*[n];
		for (int r = 0; r < n; r++)
		{
			a[r] = new int[n];
		}
		int i, j, k,sum=0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (j >= i)
				{
					a[i][j] = 1;
				}
				else a[i][j] = i + 1 - j;
				if(i==j)
				{
					sum += a[i][j];
				}
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << "the new matrix:" << endl;
		for (i = 0; i < n - 2; i++)
		{
			for (j = 0; j < n - 2; j++)
			{
				cout << a[i][j] << " ";
			} 
			cout << endl;
		}
		cout << "sum=" << sum << endl;



	}
}
