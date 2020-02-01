#include "iostream"
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string number;
	double x, y;
	double dismax = 10005;
	double dismin = -2;
	string number1, number2;

	for (int i = 0; i < n; i++)
	{
		cin >> number >> x >> y;
		if (sqrt(pow(x, 2)+pow(y,2)) > dismin)
		{
			dismin = sqrt(pow(x, 2)+pow(y,2));
			number1 = number;
		}
		if (sqrt(pow(x, 2)+pow(y,2)) < dismax)
		{
			dismax = sqrt(pow(x, 2)+pow(y,2));
			number2 = number;
		}
	}

	cout << number2 << " " << number1 <<endl;
	return 0;
}