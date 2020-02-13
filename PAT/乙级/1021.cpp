#include <iostream>

using namespace std;

int arr[10] = {0};

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i] - '0']++;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (arr[i] != 0)
            cout << i << ":" << arr[i] << endl;
    }
    return 0;
}
