#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int main()
{
	cout << "请输入名字拼音，以#结束" << endl;
	char ch, str[20];
	int i=0, j, k, t;
	cin.get(ch);
	while (ch != '#')
	{
		str[i] = ch;
		cin.get(ch);
		i++;
	}
	if (i + 1 <= 6)
	{
		for(j=i;j>=0;j--)
		cout<<int(str[j])
	}
	
}