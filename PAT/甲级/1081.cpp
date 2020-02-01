#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

struct node
{
    long long  num;
    long long  den;
    long long  flag;
};

node arr[101];

int main()
{
    long long  n;
    long long  index = 0;
    cin >> n;
    cin.get(); // getline前面最好吸收个回车
    string str;
    getline(cin, str);
    for (long long  i = 0; i < str.length(); i++)
    {
        if (str[i] == '/') // 只能和单引号判断
        {
            long long  j = i - 1; 
            while (str[j] != ' ' && j > 0)
                j--;
            // cout << j << "  ";
            if (str[j + 1] == '-')
            {
                arr[index].flag = true;
                arr[index].num = stoi(str.substr(j + 2, i));
            }
            else
            {
                if (j == 0) arr[index].num = stoi(str.substr(0, i));
                else arr[index].num = stoi(str.substr(j + 1, i));
            }
            long long  k = i + 1;
            if (str[k] != ' ')
                k++;
            arr[index].den = stoi(str.substr(i + 1, k));
            index ++;
        }
    }

    // for (long long  i = 0; i < index; i++)
    // {
    //     cout << arr[i].num << " " << arr[i].den << " " << arr[i].flag << endl; 
    // }

    long long  max = arr[0].den;
    for (long long  i = 1; i < index; i++)
    {
        max = max > arr[i].den ? max : arr[i].den;
        // cout << max << endl;
        long long  temp = max;
        // cout <<  << "---------" << max % temp;
        while( max % arr[i-1].den != 0 || max % temp != 0)
        {
            max++;
        }
    }
    long long  sum = 0;
    for (long long  i = 0; i < index; i++)
    {
        if (arr[i].flag == true)  sum -= arr[i].num * (max / arr[i].den);
        else sum += arr[i].num * (max / arr[i].den);
    }
    if (sum % max == 0)
    {
        cout << sum / max ;
        return 0;
    }
    else
    {
        if (sum / max != 0 && sum / max >= 1)
        {
            cout << sum / max << " ";
            sum -= (sum/max) * max;
            long long  temp = sum;
            long long  sum1 = sum;
            long long  max1 = max;
            while (max1 % sum1 != 0)
            {
                temp = max1 % sum1;
                max1 = sum1;
                sum1 = temp;
            }   
            cout << sum / temp << "/" << max / temp;
        }
        if ((sum) * (max) < 0)
        {
            sum = abs(sum);
            max = abs(max);
            if ((sum) / (max) >= 1)
            {
                cout << "-" << (sum) / (max) <<" ";
                sum -= ((sum) / (max)) * (max);
            }
            long long  sum1 = sum;
            long long  max1 = max;
            long long  temp = sum;
            while (max1 % sum1 != 0)
            {
                temp = max1 % sum1;
                max1 = sum1;
                sum1 = temp;
            }
            cout << "-" << (sum/temp) << "/" << abs(max/temp);
        }
        return 0;
    } 
}