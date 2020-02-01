#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int prime(int n) 
{ 
	if (n < 2)
		return 0;
	for (int i = 2; i <= (int) sqrt((double) n); i++) 
    {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
    int num, radix;
    string str;
    int sum = 0;
    int flag = 0;
    while(1)
    {
        cin >> num;
        if (num < 0)
            return 0;
        else
        {
            cin >> radix;
            // 判断原来的数 是素数
            if(prime(num) == 0) 
            {
                printf("No\n");
                continue;
            }
            while(num != 0)
            {
                str += to_string(num % radix);
                num = num / radix;
            }
            // cout << str << "=====>";
            for (int i = 0; i < str.length(); i++)
            {
                sum += pow(radix, str.length() - i - 1) * (str[i] - '0');
            }
            // cout << sum << endl;
            flag = prime(sum);
            if (flag == 1)
                cout << "Yes" << endl;
            else 
                cout << "No" << endl;
            sum = 0;
            str = "";
        }
    }
    return 0;
}