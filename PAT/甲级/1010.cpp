#include <iostream>
#include <cmath>
// #include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    long long n1, n2, tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    // cout << n1 << n2 << tag << radix;
    string str1, str2;
    char c = radix - '0';
    if (c >= 'a' && c <= 'z')
        radix += 9 + c - 'a' + 1;
    if (tag == 1)
    {
        string temp = to_string(n1);
        n1 = 0;
        for (long long i = 0; i < temp.length(); i++)
            n1 += (temp[i] - '0') * pow(radix, temp.length() - i - 1);
        long long radix_temp = 1;
        for (long long i = 0; i < temp.length(); i++)
        {
            if (temp[i] >= '0' && temp[i] <= '9' && temp[i] - '0' >= radix_temp)
                radix_temp = temp[i] - '0';
            if (temp[i] >= 'a' && temp[i] <= 'z' && temp[i] - 'a' + 10 >= radix_temp)
                radix_temp = temp[i] - 'a' + 10;
        } 
        temp = "";
        radix_temp += 1;
        long long num = n2;
        long long num1 = n1;
        for (long long i = 2; i < radix_temp; i++)
        {
            while(n2 != 0)
            {
                temp += to_string(n2 % i);
                n2 = n2 / radix;
            }
            reverse(temp.begin(), temp.end());
            for (long long j = 0; j < temp.length(); j++)
            {
                n1 -= (temp[j] - '0')*(pow(i, temp.length() - j - 1));
            }
            // cout << n1 << endl;
            if (n1 == 0)
            {
                cout << i;
                return 0;
            }
            temp = "";
            n2 = num;
            n1 = num1;
        }
    }
    if (tag == 2)
    {
        string temp = to_string(n2);
        n2 = 0;
        for (long long i = 0; i < temp.length(); i++)
            n2 += (temp[i] - '0') * pow(radix, temp.length() - i - 1);
        long long radix_temp = 1;
        for (long long i = 0; i < temp.length(); i++)
        {
            if (temp[i] >= '0' && temp[i] <= '9' && temp[i] - '0' >= radix_temp)
                radix_temp = temp[i] - '0';
            if (temp[i] >= 'a' && temp[i] <= 'z' && temp[i] - 'a' + 10 >= radix_temp)
                radix_temp = temp[i] - 'a' + 10;
        } 
        temp = "";
        radix_temp += 1;
        long long num = n1;
        long long num2 = n2;
        for (long long i = 2; i < radix_temp; i++)
        {
            while(n1 != 0)
            {
                temp += to_string(n1 % i);
                n1 = n1 / radix;
            }
            reverse(temp.begin(), temp.end());
            for (long long j = 0; j < temp.length(); j++)
            {
                n2 -= (temp[j] - '0')*(pow(i, temp.length() - j - 1));
            }
            if (n2 == 0)
            {
                cout << i;
                return 0;
            }
            temp = "";
            n1 = num;
            n2 = num2;
        }
    }
    cout << "Impossible";
    return 0;
}

