#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100002];

int main(int argc, char const *argv[])
{
    long long n, p;
    cin >> n >> p;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long min = arr[0];
    long long value = min * p;
    long long count = 0;
    for (long long i = 0; i < n; i++)
    {
        if (arr[i] <= value)
        {
            count ++;
        }
    }
    cout << count;
    return 0;
}
