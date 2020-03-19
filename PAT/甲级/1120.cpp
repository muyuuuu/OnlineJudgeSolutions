#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10004];
vector <int> v;

int main(int argc, char const *argv[])
{
    int n;
    int temp;
    string str;
    int key = 0;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        str = to_string(temp);
        for (int j = 0; j < str.length(); j++)
            key += (str[j] - '0');
        if (arr[key] == 0){
            count++;
            arr[key]++;
            v.push_back(key);
        }
        key = 0;
    }
    sort(v.begin(), v.end());
    cout << count << endl;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
            cout << v[i];
        else
            cout << " " << v[i];
    }
    return 0;
}
