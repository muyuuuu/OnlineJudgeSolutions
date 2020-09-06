#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v, m;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s[1] == 'o')
        {
            if (v.empty())
            {
                cout << "Invalid" << endl;
                continue;
            }
            else
            {
                cout << v.back() << endl;
                v.pop_back();
            }
        }
        if (s[1] == 'u')
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        if (s[1] == 'e')
        {
            if (v.empty())
            {
                cout << "Invalid" << endl;
                continue;
            }
            else
            {
                m.clear();
                m.assign(v.begin(), v.end());
                sort(m.begin(), m.end());
                if (v.size() % 2 == 0) cout << m[v.size() / 2 - 1] << endl;
                else cout << m[(v.size() + 1) / 2 - 1] << endl;   
            }
        }
    }
    return 0;
}
