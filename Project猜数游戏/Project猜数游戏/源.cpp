#include<iostream>
using namespace std;
int main()
{
	while (1)
	{
		cout << "想好一个0到1000之间的整数，计算机为您猜出。"<<endl<<"如果计算机猜得过大，请输入1，猜小了请输入-1，猜中了请输入0" << endl;
		int a, b = 500;
		cout << endl;
		while (cin>>a)
		{
			while (1)
			{
			
				if(a!=1&&a!=-1&&a!=0)
				{
					cout << "输入错误，请重新输入。" << endl; continue;
					break;
				}
			}
			{
				do {
				b += 100;
			} while (a == -1);
			do {
				b -= 10;
			} while (a ==1);
			do { ++b; }
			while (a == -1);
			if
				

		}
	}
}