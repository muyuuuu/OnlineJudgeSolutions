#include <iostream>
using namespace std;
int main() {
    long long a, b, c, d, e, f, G, S, K;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
	if (c + f >= 29){
		K = c + f - 29;
		b += 1;
	}
	else K = c + f;
	if (b + e >= 17){
		S = b + e - 17;
		a += 1;
	} 
	else S = b + e;
	G = a + d;
	cout << G << "." << S << "." << K ;
    return 0;
}
