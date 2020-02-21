#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    int key = 0;
    int pos;
    char arr[6] = {'P', 'A', 'T', 'e', 's', 't'};
    while (str.find('P') != string::npos || str.find('A') != string::npos || str.find('T') != string::npos || str.find('e') != string::npos || str.find('s') != string::npos || str.find('t') != string::npos)
    {
        if (str.find(arr[key]) != string::npos)
        {
            cout << arr[key];
            pos = str.find_first_of(arr[key]);
            str.erase(pos, 1);
        }
        key++;
        if (key == 6)
            key = 0;
    }
    return 0;
}
