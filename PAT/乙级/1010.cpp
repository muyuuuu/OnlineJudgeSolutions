#include "iostream"

using namespace std;

int main()
{
	int a, b;
	int flag = 0;
	while(cin >> a >> b)
	{
		if (b != 0)
		{
			if (flag == 1)
				cout<<" ";
			printf("%d %d", a*b, b-1);
			flag = 1;
		}
		if (flag == 0)
		{
			printf("%d %d", 0, 0);
			break;
		}
		if (b == 0)
		{
			break;
		}
	}
	return 0;
}