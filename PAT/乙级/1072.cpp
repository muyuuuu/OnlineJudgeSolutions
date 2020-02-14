#include <iostream>

using namespace std;

int arr[10004] = {0};

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int temp, temp1;
    string name;
    int num = 0, num1 = 0, flag = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        arr[temp] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> name >> temp;
        for (int j = 0; j < temp; j++)
        {
            cin >> temp1;
            if (arr[temp1] == 1)
            {
                num1++;
                if (flag == 0)
                {
                    cout << name << ":";
                    flag = 1;
                }
                if (flag == 1)
                    printf(" %04d", temp1);
            }
        }
        if (flag == 1)
        {
            cout << endl;
            num++;
            flag = 0;
        }
    }
    cout << num << " " << num1;
    return 0;
}
