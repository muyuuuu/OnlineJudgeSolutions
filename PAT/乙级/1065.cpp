#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> couple;
int arr[100002] = {0};
vector<int> v, v1;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int str1, str2;
    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2;
        if (str1 == 0) str1 = 100001;
        if (str2 == 0) str2 = 100001;
        couple[str1] = str2;
        couple[str2] = str1;
        // cout << "here" << endl;
    }
    int m;
    cin >> m;
    v.resize(m);
    v1.resize(0);
    // cout << m << "----------" << endl;
    int count = 0, temp = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (temp == 0) temp = 100001;
        arr[temp] = 1;
        v[i] = temp;
    }
    // 如果 map 中存在，且 数组两端均为 1 表示不单身
    for (int i = 0; i < v.size(); i++)
    {
        if (couple[v[i]] != 0 && arr[v[i]] == 1 && arr[couple[v[i]]] == 1)
            continue;
        else
        {
            count++;
            v1.push_back(v[i]);
        }
    }
    cout << count << endl;
    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++)
    {
        if (i == 0)
            printf("%05d", v1[i]);
        else
            printf(" %05d", v1[i]);
    }
    return 0;
}
