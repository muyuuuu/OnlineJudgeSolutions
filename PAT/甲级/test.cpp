#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int a[7] = {1, 2, 0, 2, 0, 0, 1};
    vector <int> in(a, a + 7);
    // for (int i = 0; i < in.size(); i++)
        // cout << in[i] << " ";
    vector <int> arr[2];
    arr[0].push_back(1);
    arr[0].push_back(2);
    for (auto it : arr[0])
        cout << it << " ";
    return 0;
}
