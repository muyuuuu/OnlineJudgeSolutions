#include <iostream>

using namespace std;

int main()
{
	int a;
	cin >> a;
	int count = 0;
	string name, birth, max_bir("2014/09/07"), min_bir("1814/09/04");
	string max_name, min_name;
	for (int i = 0; i < a; ++i)
	{
		cin >> name >> birth;
		if (birth >= "1814/09/06" && birth <= "2014/09/06")
		{
			count++;
			if (birth > min_bir)
			{
				min_bir = birth;
				min_name = name;
			}
			if (birth < max_bir)
			{
				max_bir = birth;
				max_name = name;
			}
		}
	}
	cout << count;
  	if(count != 0)
		cout<<" "<<max_name<<" "<<min_name;
	return 0;
}