#include<iostream>
using namespace std;
int main()
{
	int a£¬b;
	while (cin >> a>>b)
	{
		int i, j=0, k=0;
		int p[] = { 20030001 ,20030002 ,20030005 ,20030007 ,20030010 };
		char*str[] = { "li ming","zhang qing","liu xiao ping " ,"wang ying","lu pei" };
		for (i = 0; i < 5; i++)
		{
			if (p[i]==a)
			{
				k = 1;
				cout << str[i]<<endl;
				break;
			}
		}
		if(k==0)
		{
			cout << "Can't found!" << endl;
		}
		for (i = 0; i < 5; i++)
		{
			if (p[i] == b)
			{
				j = 1;
				cout << str[i] << endl;
				break;
			}
		}
		if (j == 0)
		{
			cout << "Can't found!" << endl;
		}
	}
}