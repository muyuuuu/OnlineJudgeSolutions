#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	float maxn = -2;
	int a, b;
	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b;
		if( sqrt(pow(a, 2) + pow(b, 2)) > maxn)
		{
			maxn = sqrt(pow(a, 2) + pow(b, 2));
		}
	}
	printf("%.2f", maxn);
	return 0;
}