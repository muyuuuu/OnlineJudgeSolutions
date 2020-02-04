#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    int pri = 0;
    double sum = 0;
    int key = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int flag = 0;
        int len = str.length();
        pri = 0;
        for (int i = 0; i < len; i++)
        {
            if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.') || (str[i] == '-') || (str[i] == '+'))
            {
                if (str[i] == '.')
                {
                    pri ++;
                    if (len - i >= 4)
                    {
                        cout << "ERROR: " + str + " is not a legal number" << endl;
                        break;
                    }
                }
                if ((i != 0) && ( (str[i] == '-') || (str[i] == '+') ))
                {
                        cout << "ERROR: " + str + " is not a legal number" << endl;
                        break;
                }
                if (pri >= 2)
                {
                    flag = 1;
                    cout << "ERROR: " + str + " is not a legal number" << endl;
                    break;
                }
            } 
            else
            {
                flag = 1;
                cout << "ERROR: " + str + " is not a legal number" << endl;
                break;
            }
            if ((i == len - 1) && (flag == 0))
            {
                double num = stof(str);
                if (num >= -1000 &&  num <= 1000)
                {
                    sum += num;
                    key++;
                }
                else
                {
                    cout << "ERROR: " + str + " is not a legal number" << endl;
                }
            }
        }
    }
    if (key == 0)
    {
        cout << "The average of 0 numbers is Undefined";
    }
    // 不写 else if 会执行最后一个 else
    else if (key == 1)
    {
        cout << "The average of 1 number is ";
        printf("%.2f", sum);
    }
    else
    {
        cout << "The average of " << key << " numbers is ";
        printf("%.2f", sum / key);
    }
    return 0;
}