#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a;
	while(cin>>a)
	
	{
		int b[],i=0,j,sum;
		for (; a / 10 != 0; i++)
		{
			int c = a, k;
			for (k = 1; c / 10 != 0; k++)
			{
				c /= 10;
			}
			b[i] = c;
			if (c == 8)
				cout << "yes" << endl;
			continue;
			  a = a % (pow(10, k));
		}
		for (j = 0; j <= i; j++)
		{
			sum += a[j];
		}
		
	}
}