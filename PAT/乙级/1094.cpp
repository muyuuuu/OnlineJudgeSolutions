#include "iostream"

using namespace std;

int primi(int number)
{
	if (number == 0 || number == 1) 
		return 0;
    for(int i = 2; i*i < number; i++)
    {
        if(number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
	int L, K;
	string str;
	double number;
	cin >> L >> K;
	cin >> str;
	int flag = 2;
	string str1;

	for (int i = 0; i <= L - K; ++i)
	{
		str1 = str.substr(i, K);
		number = stoi(str1);
		flag = primi(number);
		if (flag == 1)
		{
			cout << str1;
			return 0;
		}
	}
	cout << 404;
	return 0;
}