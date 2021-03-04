#include "iostream"

using namespace std;

template <class T> 
T GetMax(T a, T b)
{
	T result;
	result = (a > b) ? a : b;
	return result;
}

int main(int argc, char const *argv[])
{
	int i = 5, j = 6, k;
	double m = 5.52, n = 6.63, l;
	k = GetMax(i, j);
	l = GetMax(m, n);
	cout << k << "  " <<  l << endl;
	return 0;
}