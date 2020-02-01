#include <iostream>
#include <vector>
using namespace std;

double a[105][1005] = {0};

int main()
{
	int cla, city;
	cin >> cla >> city;

	for (int i = 0; i < city; ++i)
	{
		for (int j = 0; j < cla; ++j)
		{
			cin >> a[i][j];
		}
	}

	int max = -3;
	for (int i = 0; i < city; ++i)
	{
		for (int j = 0; j < cla; ++j)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}
	}

	cout << max << endl;

	max = -3;
	for (int j = 0; j < cla; ++j)
	{
		for (int i = 1; i < city; ++i)
		{
			a[0][j] += a[i][j];
		}
	}

	for (int i = 0; i < city; ++i)
	{
		if ( a[0][i] > max)
			max = a[0][i];
	}

	int flag = 0;

	for (int i = 0; i < cla; ++i)
	{
		if ( a[0][i] == max )
		{
			if (flag == 1)
			{
				cout << " ";
			}
			cout << (i + 1);
			flag = 1;
		}
	}
	return 0;
}