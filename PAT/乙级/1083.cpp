#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n+1] = {0};
	int num;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &num);
		num = abs(num - i);
		a[num] += 1;
	}
	for (int i = n; i >= 0; --i)
	{
		if (abs(a[i]) >= 2)
		{
			cout << i << " " << a[i] << endl;
		}
	}
	return 0;
}