#include "iostream"
#include <cmath>
using namespace std;

int main()
{
	int a = 0, sur;
	char str;
	cin >> a >> str;
	sur = a;
	int row = 1, flag = 1;
	if (a == 0)
	{
		cout<<0;
		return 0;
	}
	if (a < 7)
	{
		if (a == 0)
		{
			row = 0;
			sur = 0;
		}
		else
		{
			row = 1;
			sur = a - 1;
		}
	}
	if (a >= 7)
	{
		while(a >= 2*(row+1))
		{
			row += 2;
			flag = 2 * (row);
			a -= flag;  //放在最后
		}
	}
	int temp = 0;
	for (int i = 3; i <= row; i=i+2)
	{
		temp = 2 * i;
		sur -= temp;
		if (i == row)
			sur = sur - 1;
	}
	for (int i = row/2+1; i >= 1; --i)
	{
		for (int j = 0; j < row/2+1-i; ++j)
		{
			printf(" ");
		}
		for (int j = 2*i-1; j > 0; --j)
		{
			printf("%c", str);
		}
		printf("\n");
	}
	for (int i = 2; i <= row/2+1; ++i)
	{
		for (int j = 0; j < row/2+1-i; ++j)
		{
			printf(" ");
		}
		for (int j = 2*i-1; j > 0; --j)
		{
			printf("%c", str);
		}
		printf("\n");
	}
	cout<<sur;
	return 0;
}
