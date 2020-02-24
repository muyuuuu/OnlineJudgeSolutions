#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double sum = 0.0, temp;
    for (int i = 1; i <= n; i++) { 
        cin >> temp;
        // i 表示前面的组合 
        // n - i + 1 表示包括 i 的后面的组合 
        sum += temp * i * (n - i + 1);
    }
    printf("%.2f", sum);
    return 0;
}