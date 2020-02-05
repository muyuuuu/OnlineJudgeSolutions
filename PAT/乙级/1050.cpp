#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arr[101][101];

bool cmp(int a, int b)
{
    if (a > b)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    int temp;
    int min = 10000;
    int row = 0, col = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    int m = sqrt(n);
    for (int i = m; i > 0; i--)
    {
        for (int j = m; j <= n; j++)
        {
            if (i * j == n)
            {
                if (j - i <= min)
                {
                    min = j - i;
                    row = j;
                    col = i;
                }
            }
        }
    }
    int key = 0;
    int flag = 0, col_flag = 0;
    int a = row, b = col;
    if (col == 1)
    {
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << endl;
        }
        return 0;
    }
    if (row == 2)
    {
        cout << v[0] << " " << v[1] << endl;
        cout << v[3] << " " << v[2] << endl;
        return 0;
    }
    while(col > 1 && flag < row)
    {
        int i = flag;
        for (int j = flag; j < col; j++)
        {
            arr[i][j] = v[key];
            key++;
            // 左到右
            // cout << i << "  "<< j << "  " << arr[i][j] << endl;
            if (j == col - 1)
            {
                i += 1;
                break;
            }
        }
        for (int k = i; k < row; k++)
        {
            arr[k][col - 1] = v[key];
            // 右到下
            // cout << k << "  "<< col - 1 << "  " << arr[k][col - 1] << endl;
            key ++;
            if (k == row - 1)
            {
                if (flag == row - 1)
                    break;
                for (int j = col - 2; j > flag; j--)
                {
                    arr[k][j] = v[key];
                    // 下到左
                    // cout << k << "  "<< j << "  " << arr[k][j] << endl;
                    key ++ ;
                }
            }
        }
        // 左到上
        for (int l = row - 1; l > flag; l--)
        {
            if (flag == col - 1)
                break;
            else
            {
                arr[l][flag] = v[key];
                // cout << l << "  " << flag << "  " << v[key] << endl;
                key++;
            }
        }
        row = row - 1;
        if (col == 2 && col_flag == 0)
        {
            arr[1][flag] = v[key];
            break;
        }
        col_flag = 1;
        col = col - 1;
        flag ++;
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << arr[i][j];
            if (j != b - 1)
                cout << " ";
        }
        if (i != a - 1)
            cout << endl;
    }
    return 0;
}