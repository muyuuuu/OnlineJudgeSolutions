#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;

vector <float> arr;

int main(int argc, char const *argv[])
{
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    float temp;
    while (arr.size() != 1)
    {
        temp = arr[0] / 2 + arr[1] / 2;
        if (arr.size() == 2)
            break;
        arr.erase(arr.begin() + 0);
        arr.erase(arr.begin() + 0);
        arr.insert(arr.begin() + 0, temp);
    }
    cout << floor(temp);
    return 0;
}
