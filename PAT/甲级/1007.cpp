#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k;
    cin >> k;
    int left = 0, right = 0;
    int temp = 0;
    vector <int> v(0);
    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    temp = 0;
    int sum = -1; 
    // 可能有0，但不是全部都是负数的0，所以不能 <= 0。
    int flag = 0;
    for (int i = 0; i < k ; i++)
    {
        temp = temp + v[i];
        if (temp < 0)
        {
            temp = 0;
            flag = i + 1;
        }
        else if (temp > sum)
        {
            sum = temp;
            left = flag;
            right = i;
        }   
    }
    if (sum < 0)
    {
        cout << 0 << " " << v[0] << " " << v[k-1];
    }
    else
    {
        cout << sum << " " << v[left] << " " << v[right];
    }
    // cout << left << "  " << right << "  " << endl;
    return 0;
}

