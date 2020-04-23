#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> ans, temp;

int main(int argc, char const *argv[])
{
    int n, a, cnt = 0;
    string str;
    cin >> n;
    cin .get();
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "Push")
        {
            cin >> a;
            ans.push_back(a);
            cnt++;
        }
        if (str == "Pop")
        {
            if (cnt <= 0)
            {
                cout << "Invalid" << endl;
                continue;
            }
            else
            {
                cout << ans[ans.size() - 1] << endl;
                ans.pop_back();
                cnt--;
            }
        }
        if (str == "PeekMedian")
        {
            if (cnt <= 0)
            {
                cout << "Invalid" << endl;
                continue;
            }
            temp = ans;
            sort(temp.begin(), temp.end());
            int s = temp.size();
            s % 2 == 0 ? cout << temp[s / 2 - 1] << endl : cout << temp[(s + 1) / 2 - 1] << endl;
        }
    }
    return 0;
}
