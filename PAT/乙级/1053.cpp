#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    float n, e, d;
    cin >> n >> e >> d;
    float count = 0, count1 = 0;
    float temp = 0, temp1, key = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            cin >> temp1;
            if (temp1 < e)
                key++;
        }
        if (key > (temp / 2))
            temp > d ? count1++ : count++;
        key = 0;
    }
    printf("%.1f%s %.1f%s", count / n * 100, "%", count1 / n * 100, "%");
    return 0;
}
