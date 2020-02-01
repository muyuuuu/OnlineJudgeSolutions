#include <iostream>
using namespace std;
int main() {
    long long n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        string s = to_string(num);
        long long len = s.length();
        long long a = stoi(s.substr(0, len/2));
        long long b = stoi(s.substr(len/2));
        if (a * b != 0 && num % (a * b) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
