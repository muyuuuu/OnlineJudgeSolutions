#include <iostream>

using namespace std;

int main()
{
	int a;
	cin >> a;

	string group;
	int num[1002] = {0};
	int number;
	int position = 1;
	for (int i = 1; i <= a; ++i)
	{
		cin >> group >> number;
		position = group.find("-");
		group = group.substr(0, position);
		position = atoi(group.c_str());
		num[position] += number;
	}

	int max = -2;
	int count = 0;

	for (int i = 1; i <= 1001; ++i)
	{
		if (num[i] > max)
		{
			count = i;
			max = num[i];
		}
	}

	cout << count << " " << max;

	return 0;
}