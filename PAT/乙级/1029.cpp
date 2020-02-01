#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
	string str1, str2;
	cin >> str1 >> str2;
	int len = str1.length();
	string str;
	int position = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str1[i] == str2[position])
		{
			position++;
			continue;
		}
		if (str1[i] != str2[position])
		{
			if (str.find(toupper(str1[i])) == string::npos)
			{
				str.push_back(toupper(str1[i]));
			}
		}
	}
	cout << str;
	return 0;
}