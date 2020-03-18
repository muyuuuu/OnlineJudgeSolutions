#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, int> m;
vector<char> v;

int main(int argc, char const *argv[])
{
    int k;
    cin >> k;    
    string str;
    cin >> str;
    int len = str.length(), key = 1;
    for (int i = 0; i <= len - k; i += key)
    {
        key = 1;
        int j = i + 1;
        while (str[j] == str[i])
        {
            j++;
            key++;
        }
        if (key % k == 0 && m[str[i]] != 2)
        {
            if (m[str[i]] != 1)
                v.push_back(str[i]);    
            m[str[i]] = 1;
        }
        else
            m[str[i]] = 2;
    }
    // 2 aa11aaaaa
    for (auto i = v.begin(); i != v.end(); i++)
        if (m[*i] == 1)
            cout << *i;
    cout << endl;
    key = 1;
    for (int i = 0; i < len; i += key)
    {
        if (m[str[i]] == 1)
        {
            cout << str[i];
            key = k;
        }
        else
        {
            cout << str[i];
            key = 1;
        }
    }
    return 0;
}
