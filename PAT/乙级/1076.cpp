#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	int position;
	int num[n+2] = {0};
	for (int i = 0; i < n; ++i)
	{
		if (i==0)
			cin.get();
		getline(cin, str);
		position = str.find("T");
		str = str.substr(position-2, position);
		num[i] = str[0] - 'A' + 1;
	}
	for (int i = 0; i < n; ++i)
	{
		if (num[i] != 0)
		{
			cout<<num[i];
		}
	}
	return 0;
}