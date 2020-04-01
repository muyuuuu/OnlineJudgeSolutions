#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arr[101][101];

// 比较器
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
    // 将序列逆序
    sort(v.begin(), v.end(), cmp);
    int m = sqrt(n);
    // 求行数和列数
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
    // key 表示 该放序列的哪个值
    int key = 0;
    // 定义画过的圈数
    int flag = 0;
    // 标记有几行有几列， 因为 row 和 col 的值会修改。 
    // a b 用于输出时表示几行几列
    int a = row, b = col;
    // 只有一列，直接输出
    if (col == 1)
    {
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << endl;
        }
        return 0;
    }
    // 只有两行  直接输出
    if (row == 2)
    {
        cout << v[0] << " " << v[1] << endl;
        cout << v[3] << " " << v[2] << endl;
        return 0;
    }
    // 第三类情况 
    while(col > 1 && flag < row)
    {
        // i 表示从第几次开始画，flag为0，画过零次，
        // flag为1 画过一次 i就从下标1 开始，即下一行
        int i = flag;
        for (int j = flag; j < col; j++)
        {
            // 1到2 的路线 行不变 列自增
            arr[i][j] = v[key];
            key++;
            // 如果 1到2 画完了 ，就 i 自增，防止给 B 多次赋值
            if (j == col - 1)
            {
                i += 1;
                break;
            }
        }
        // 2到3 行不变 将当前行赋值给 k 列减减
        for (int k = i; k < row; k++)
        {
            arr[k][col - 1] = v[key];
            key ++;
            // 2 到 3 画完了 
            if (k == row - 1)
            {
                // 检查 3到4 和 1到2 是否重复，防止重复赋值
                // 如 5X5 的矩阵 是没有 3到4 这条线的
                if (flag == row - 1)
                    break;
                // 如果没有重复，画 3到4 col-2 防止给 C 重复复制
                for (int j = col - 2; j > flag; j--)
                {
                    arr[k][j] = v[key];
                    key ++ ;
                }
            }
        }
        // 4到1
        for (int l = row - 1; l > flag; l--)
        {
            // 4到1 和 2到3 重复的话，就不画了，防止覆盖赋好的值
            if (flag == col - 1)
                break;
            else
            {
                arr[l][flag] = v[key];
                key++;
            }
        }
        // 画完一圈，行列减一，次数加一
        row = row - 1;
        col = col - 1;
        flag ++;
    }
    // 输出结果
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