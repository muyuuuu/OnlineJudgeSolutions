#include <iostream>
using namespace std;
int main() {
    int a, now = 0, sum = 0;
    cin >> a;
    while(cin >> a) {
        cout << a << endl;
        // if(a > now)
        //     sum = sum + 6 * (a - now);
        // else
        //     sum = sum + 4 * (now - a);
        // now = a;
        // sum += 5;
    }
    // cout << sum + 5 * key;
    return 0;
}