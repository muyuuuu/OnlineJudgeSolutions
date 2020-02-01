#include <iostream>

using namespace std;

int dp[ 10001 ] = {0};

int main()
{
	int num;
	cin >> num;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i <= num; i++)
    {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	cout << dp[num] << endl;
	return 0;
}
