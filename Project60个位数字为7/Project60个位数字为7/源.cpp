
#include<iostream> 
using namespace std; 
int main() {
	int i, n = 0;
	cout << "各位数之和等于的位整数：\n";
	for (i = 100; i < 1000; i++)
		if (i % 10 + i / 10 % 10 + i / 100 == 7)
		{
			cout << i << "  ";       n++;
			if (n % 10 == 0)cout << endl;
		}
	cout << endl;
	system("pause");
}