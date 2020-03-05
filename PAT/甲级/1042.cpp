#include <iostream>

using namespace std;

string arr[54] = {" "}, ans[54] = {" "};

int order[54] = {0};

int main(int argc, char const *argv[])
{
    int k;
    cin >> k;
    for (int i = 0; i < 54; i++)
    {
        if (i < 13)
            arr[i] = "S" + to_string(i + 1);
        else if (i < 26)
            arr[i] = "H" + to_string(i - 12);
        else if (i < 39)
            arr[i] = "C" + to_string(i - 25);
        else if (i < 52)
            arr[i] = "D" + to_string(i - 38);
        else
            arr[i] = "J" + to_string(i - 51);
    }
    for (int i = 0; i < 54; i++)
        cin >> order[i];
    while (k > 0)
    {
        k--;
        for (int i = 0; i < 54; i++)
            ans[order[i] - 1] = arr[i];
        if (k != 0)
            for (int i = 0; i < 54; i++)
                arr[i] = ans[i];
    }
    for (int i = 0; i < 54; i++)
        i == 0 ? cout << ans[i] : cout << " " << ans[i];
    return 0;
}
