#include<iostream>
using namespace std;
class change
{
	mutable int a=0;
public:
	void f()const {
		a++;
		cout << a;
	}
};
int main()
{
	change a;
	a.f();
	system("pause");
}