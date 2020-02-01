#include <iostream>
#include <string>
using namespace std;

int printt(char a, char str)
{
	int b = a - '0';
	if (str != 'n')
	{
		for(int i = b; i > 0; i--)
			printf("%c", str);		
	}

	if (str == 'n')
	{
		for (int i = 1; i <= b; i++)
		{
			printf("%d", i);
		}
	}
	return 0;
}

int main()
{
	int a;
	scanf("%d", &a);
	string num = to_string(a);
	int len = num.size();
	for (int i = len; i > 0; i--)
	{
		if (i == 3)
			printt(num[len-i], 'B');
		if (i == 2)
			printt(num[len-i], 'S'); 
		if (i == 1)
			printt(num[len-i], 'n'); 
	}
	return 0;
}