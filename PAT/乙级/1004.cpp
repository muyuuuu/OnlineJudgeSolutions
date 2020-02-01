#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name[110], str[110], num[110];
	int a = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		cin>>name[i]>>str[i]>>num[i];
	}
	int minn = 101, maxn = -1;
	int m = 0, n = 0;

	for (int i = 0; i < a; i++)
	{
		int number = atoi(num[i].c_str());
		if (number > maxn)
		{
			maxn = number;
			m = i;
		}
		if (number < minn)
		{
			minn = number;
			n = i;
		}
	}

	cout<<name[m]<<'\40'<<str[m]<<endl;
	cout<<name[n]<<'\40'<<str[n];	
	return 0;
}