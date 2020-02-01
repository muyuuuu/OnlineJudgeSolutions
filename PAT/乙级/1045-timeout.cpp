// 用 vector 会超时
#include <iostream>

using namespace std;

int seq[100005] = {0};
int result[100005] = {0};

int main()
{
    int num;
    cin >> num;
    int a;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &seq[i]);
    }
    int flag = 0;
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        flag = 0;
        if (flag == 0)
            for (int j = i + 1; j < num; j++)
            {
                if (seq[i] > seq[j])
                {
                    flag = 1;
                    break;
                }
            }
        if (flag == 0)
            for (int k = i - 1; k >= 0; k--)
            {
                if (seq[k] > seq[i])
                {
                    flag = 1;
                    break;
                }
            }
        if (flag == 0)
            result[count++] = seq[i];
    }
    cout << count << endl;
    // case 2
    if (count == 0)
    {
        cout << endl;
        return 0;
    }
    for (int i = 0; i < count; i++)
    {
        if (i == 0)
            printf("%d", result[i]);
        else
            printf(" %d", result[i]);
    }
    return 0;
}
