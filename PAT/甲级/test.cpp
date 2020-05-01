#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int m = 10;
    vector<int> hash(m, 2);
    for (int i = 0; i < m; i++)
        cout << hash[i] << " ";
    return 0;
}
