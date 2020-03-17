#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum, val, sta;
	cin >> sum >> val >> sta;
	map<string, int> m;
	string str;
	bool flag = false;
	for (int i = 1; i <= sum; ++i)
	{
		cin >> str;
		if (m[str] == 1)
		{
			sta+=1;
		}
		if (i == sta && m[str] == 0)
		{
			cout << str << endl;
			m[str] = 1;
			sta += val;
			flag = true;
		}
	}
	if (flag == false)
	{
		cout << "Keep going...";
		return 0;
	}

	return 0;
}