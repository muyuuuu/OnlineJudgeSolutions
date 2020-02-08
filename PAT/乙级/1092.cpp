#include <iostream>
#include <vector>
using namespace std;

double a[105][1005] = {0};

int ans[1005];

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

	for (int j = 0; j < cla; j++)
	{
		for (int i = 0; i < city; i++)
		{
			ans[j] += a[i][j];
		}
	}

	int max = -3;

	for (int i = 0; i < cla; i++)
	{
		if (ans[i] >= max)
			max = ans[i];
	}

	cout << max << endl;

	int flag = 0;

	for (int i = 0; i < cla; i++)
	{
		if (ans[i] == max)
		{
			if (flag == 0)
			{
				cout << i + 1;
				flag = 1;
			}
			else
			{
				cout << " " << i + 1;
			}
		}
	}

	return 0;
}