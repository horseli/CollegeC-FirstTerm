#include<iostream>
using namespace std;
struct goal
{
	char n[20];
	int g;
};
int main()
{
	int s;
	while (cin >> s)
	{
		goal*c=new goal [s];
		int i, j, k,q=0;
		for (i = 0; i < s; i++)
		{
			cin >> c[i].n >> c[i].g;
			
		}
		for (j = 0; j < s-1; j++)
		{
			q = j;
			for (k = j + 1; k < s; k++)
			{
				if(c[q].g>c[k].g)
				{
					goal t = c[q];
					c[q] = c[k];
					c[k]= t;
					
				}
			}
		}
		cout << c[s - 1].n << " " << c[s-1].g << endl;
		for (int m = 0; m < s-1; m++)
		{
			if (c[m].g == c[s - 1].g)
				cout <<c[m].n<<" "<< c[m].g<<endl ;
		}
		
		}
}
