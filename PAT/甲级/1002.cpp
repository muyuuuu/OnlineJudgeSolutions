#include <iostream>
using namespace std;

int main()
{
	float array[1005] = {0}, number=0;
	int number1, number2;
	int t;
	scanf("%d", &number1);
	for (int i = 0; i < number1; i++)
	{
		scanf("%d%f", &t, &number);
		array[t] = array[t] + number;
	}

	scanf("%d", &number2);
	for (int i = 0; i < number2; i++)
	{
		scanf("%d%f", &t, &number);
		array[t] = array[t] + number;
	}

	int cnt = 0;
	for (int count = 0; count < 1005; count++)
	{
		if (array[count] != 0)
		{
			cnt = cnt + 1;
		}
	}
	printf("%d", cnt);
	
	for (cnt = 1004; cnt>=0; cnt--)
	{
		if (array[cnt] != 0)
			printf(" %d %.1f", cnt, array[cnt]);
	}

	return 0;
}