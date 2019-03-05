#include<iostream>
using namespace std;
int main()
{
	while (1)
	{
		int x, y;
		cin >> x;
		switch (x > 0 ? 1 : 0)
		{
		case 1:y = 1; break;
		case 0:switch (x < 0 ? 1 : 0)
		{
		case 1:y = -1; break;
		case 0:y = 0;
		}
		}
		cout << y << endl;
	}

}