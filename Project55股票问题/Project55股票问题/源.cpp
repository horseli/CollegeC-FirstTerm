#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int*p = new int[7];
	while (cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5] >> p[6])
	{
		int i, j, k, s;
		for (i = 0; i < 6; i++)
		{
			if(i==0)
			{
				s = p[1] - p[0];
			}
			for (j = i + 1; j < 7; j++)
			{
				if ((p[j] - p[i]) > s)
				{
					s = p[j] - p[i];
				}
			}
		}
		cout << s << endl;
	}
}