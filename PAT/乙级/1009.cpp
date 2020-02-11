#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

vector<string> v;

int main(int argc, char const *argv[])
{
    string temp;
    while (cin >> temp)
    {
        v.push_back(temp);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    if (i == 0)
        cout << v[i];
    else
        cout << " " << v[i];
    return 0;
}
