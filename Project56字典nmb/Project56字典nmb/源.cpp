#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		int*q = new int[a];
		for (int c = 0; c < a; c++)
		{
			q[c] = c + 1;
		}
		int l, i, j, k, s = a;
		for (i = 0; s / pow(10, i) != 0;)
		{
			i++;
			int e = pow(10, i);
			s = s / e;
		}
		l = i - 1;
		int**p = new int*[a];
		for (j = 0; j < a; j++)
		{
			p[j] = new int[l + 1];
		}
		for (i = 0; i < a; i++)
		{
			int t = i + 1;
			int n;
			for (n =0;t /10; )
			{
				n++;
				int fu = pow(10, n);
				t = t / fu;
			}
			t = i + 1;
			for (j = 0; j <=n; )
			{
				int m = pow(10,n-j);
				p[i][j] = t / m;
				t = t% m;
				j++;
			}
		}
		
		for (i = 0; i < a - 1; i++)
		{

			for (j = 0; j < a - i - 1; j++)
			{
				for (k = 0; k < l; k++)
				{
					if (p[j][k]>p[j + 1][k])
					{

						int w = q[j];
						q[j] = q[j + 1];
						q[j + 1] = w;
						break;
					}

				}
			}
		}
		cout << q[b - 1] << endl;
	}
}


