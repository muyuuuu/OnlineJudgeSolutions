#include <iostream>

using namespace std;
// 从1开始编号
int main()
{
	int a;
	cin >> a;
	int num[a+5]={0};
	int b, c;
	for (int i = 1; i <= a; ++i)
	{
		scanf("%d%d", &b, &c);
		num[b] += c;
	}
	int max = -1, count = 0;
	for (int i = 1; i <= a; ++i)
	{
		if (num[i] > max)
		{
			max = num[i];
			count = i;	
		}
	}
	cout << count << " " <<max;
	return 0;
}