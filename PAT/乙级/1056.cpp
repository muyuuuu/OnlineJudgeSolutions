#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string str;
	getline(cin, str);
	int sum = 0;
	for (int i = 2; i <= 2*(str[0]-'0'); i=i+2)
	{
		for (int j = 2; j <= 2*(str[0]-'0'); j=j+2)
		{
			if (j != i)
			{
				sum += (str[i] - '0')*10 + (str[j]-'0');
			}
		}
	}
	cout << sum;
	return 0;
}