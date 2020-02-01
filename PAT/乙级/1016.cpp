#include "iostream"
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	double da, db;
	string a, b;
	double counta = 0, countb = 0;
	cin >> a >> da >> b >> db;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] - '0' == da)
			counta++;
	}
	for (int i = 0; i < b.size(); ++i)
	{
		if (b[i] - '0' == db)
			countb++;
	}
	if (counta == 0 && countb == 0)
	{
		cout << 0;
		return 0;
	}
	double suma = 0;
	double temp = 0;
	for (int i = 0; i < counta; ++i)
	{
		temp = pow(10, i);
		suma += da*temp;
	}
	double sumb = 0;
	for (int i = 0; i < countb; ++i)
	{
		temp = pow(10, i);
		sumb += db*temp;
	}
	printf("%.0f", suma+sumb);
	return 0;
}