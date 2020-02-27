#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> v = { 1,2,3,4,5 };
    v.erase(v.begin() + 0);
    for (int i = 0; i < 4; i++)
        cout << " " << v[i];
    return 0;
}