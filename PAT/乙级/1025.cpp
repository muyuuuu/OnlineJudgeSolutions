# include <iostream>
# include <vector>
#include <algorithm>
using namespace std;

# define maxn 10005

int data[maxn], Next[maxn], start[maxn];

int main(int argc, char const *argv[])
{
	int add;
	int n, k;
	cin >> add >> n >> k;
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		cin >> start[i] >> data[i] >> Next[i];
	}

	int temp = 0;
	int position = 0;

	for (int i = 0; i < n; ++i)
	{
		if (start[i] == add)
			position = i;
	}

	v.push_back(data[position]);

	while (Next[position] != -1)
	{
		temp = Next[position];
		for (int j = 0; j < n; ++j)
		{
			if (start[j] == temp)
			{
				v.push_back(data[j]);
				position = j;
			}
		}
	}

	temp = 0;

	for (int i = 0; i < v.size(); i+=k)
	{
		if (i+k-1 > v.size())
		{
			break;
		}
		reverse(v.begin()+i, v.begin()+k+i);
	}

	int flag = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			if (data[j] == v[i])
				if (i == 0)
					printf("%05d %d ", start[j], v[i]);
				else
					printf("%05d\n%05d %d ", start[j], start[j], v[i]);
		}
	}

	printf("-1");

	return 0;
}