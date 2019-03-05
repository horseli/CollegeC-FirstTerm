#include<iostream>
using namespace std;
int main()
{
	char*c = new char[10];
	while (cin >> c)
	{
		int i, j, k = 0,n,m ,t;
		for (i = 0; c[i] != '\0'; i++)
		{
			;
		}
		t = i;
		if (t % 2 != 0)
		{
			for (n = 0; n <(t - 1) / 2; n++)
			{
				if(c[n]!=c[t-1-n])
				{
					k = 1;
					cout << "No!" << endl;
					break;
				}
			}
		}
		else if(i%2==0)
		{
			for (j = 0; j <= t / 2 - 1; j++)
			{
				if (c[j] != c[t - 1 - j])
				{
					cout << "No!" << endl;
					k = 1;
					break;
				}
			}
		}
			if (k != 1)
			{
				cout << "Yes!" << endl;
			}
		
	}
}
