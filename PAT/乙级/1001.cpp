#include <iostream>

using namespace std;

int main()
{
	int a;
	scanf("%d", &a);
	int n = 0;
	while(a != 1)
	{
		if (a % 2 == 0)
		{
			a = a / 2;
			n = n + 1;
			// printf("%d\n", a);
		}
		else
		{
			a = (3 * a + 1) / 2;
			// printf("%d\n", a);
			n = n + 1;
		}
	}
	printf("%d", n);
	return 0;
}