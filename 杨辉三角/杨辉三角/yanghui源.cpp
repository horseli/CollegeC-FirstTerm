#include<iostream>
using namespace std;
int main()
{
	while (1)
	{
		cout << "Hpw many lines?    ";
		int n, *p = NULL, i, j, k£¬l;
		cin >> n;
		p = new int[n];
		for (i = 0; i < n; i++)
		{
			p[0] = 1;
			p[i] = 1;
			for (j = i; j > 0; j--)
			{

				if (j > 1)
				{
					p[j - 1] = p[j - 2] + p[j - 1];
				}

			}
			for (k = 0; k <= i; k++)
			{
				for (l = i - 1; l >= 0; i--)
				{
					cout << " ";
				}
				cout << p[k] << " ";
			}
			cout << endl;
		}

	}
}