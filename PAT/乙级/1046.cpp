#include "iostream"

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b;
	int a1, b1;
	int count = 0, count1 = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> a1 >> b1;
		if (b == a + a1)
			count1++;
		if (b1 == a + a1)
			count++;
		if (b == a + a1 && b1 == a + a1)
		{
			count--;
			count1--;
		}
	}
	cout << count << " " << count1;
	return 0;
}