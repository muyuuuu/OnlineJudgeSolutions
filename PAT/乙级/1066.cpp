#include<iostream>

using namespace std;

int arr[501][501];

int main()
{
    int row = 0;
    int col = 0;
    int a = 0;
    int b = 0;
    int value = 0;
    
    int temp;
    scanf("%d%d%d%d%d", &row, &col, &a, &b, &value);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> temp;
            if (temp >= a && temp <= b)
                arr[i][j] = value;
            else
                arr[i][j] = temp;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == col - 1)
                printf("%03d", arr[i][j]);
            else
                printf("%03d ", arr[i][j]);
        }
        cout << endl;
    }
    return 0;
}