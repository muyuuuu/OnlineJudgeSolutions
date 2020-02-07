#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
void showvector(std::vector<T> v)
{
    // 因此，如果你想直接告诉编译器T::iterator是类型而不是变量，只需用typename修饰：
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }
    // cout << endl;
}

int main(int argc, char const *argv[])
{
	string table;
	string num1;
	string num2;
	std::vector<int> ans;	

	cin >> table;
	cin >> num1 >> num2;

	if (num1.length() > num2.length())
		num2.insert(num2.begin(), num1.length()-num2.length(), '0');

	if (num1.length() < num2.length())
		num1.insert(num1.begin(), num2.length()-num1.length(), '0');

	int ad = 0;
	int ba = 0;
	int temp;

	for (int i = num2.length()-1; i >= 0; i--)
	{
		if (table[i] == '0')
			temp = 10;
		else
			temp = table[i] - '0';
		if (num2[i] - '0' + num1[i] - '0' + ad > temp)
		{
			ba = num2[i] - '0' + num1[i] - '0' - temp + ad;
			ans.insert(ans.begin(), 1, ba);
			ad = 1;
			// showvector(ans);
			// cout << endl;
		}
		if (num2[i] - '0' + num1[i] - '0' + ad < temp)
		{
			ba = num2[i] - '0' + num1[i] - '0' + ad;
			ans.insert(ans.begin(), 1, ba);
			// showvector(ans);
			ad = 0;
			// cout << "--" << endl;
		}
		if (num2[i] - '0' + num1[i] - '0' + ad == temp)
		{
			ad = 1;
			ans.insert(ans.begin(), 1, 0);
			// showvector(ans);
			// cout << endl;
		}
	}
	if (ad == 1)
	{
		ans.insert(ans.begin(), 1, 1);
	}

	// 去除0
	int len = ans.size();
	for (int i = 0; i < len; i++)
	{
		if (ans[i] == 0)
		{
			ans.erase(ans.begin() + 0);
			len = ans.size();
			if (len == 1)
			{
				cout << "0";
				return 0;
			}
			i = 0;
		}
		else
			break;
	}

	showvector(ans);
	return 0;
}