#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	int a;
	cin >> s >> a;
	string s1;
	int temp = 0;

	for (int i = 0; i < s.length(); ++i)
	{
		temp = temp * 10 + (s[i] - '0');
		if (temp % a == 0)
		{
			s1.append(to_string(temp/a));
			temp = 0;
		}
		if (temp % a != 0)
		{
			s1.append(to_string(temp/a));
			temp = temp % a;
		}
	}

	int len = s1.size();
	int position = 0;

	for (int i = 0; i < len; ++i)
	{
		if (s1[i] == '0')
    	{	
    		position++;
    		continue;
    	}
    	if (s1[i] != '0')
    	{	
    		break;
    	}
	}
	s1.erase(0, position);
	if (s1.size() == 0)
		cout << "0";
	cout << s1 ;
    cout << " " << temp;
	return 0;
}