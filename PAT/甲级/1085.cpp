#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
	int n;
	long long p;
	cin >> n >> p;
	int a;
	for (int i = 0; i < n; i++){
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end()); 
	int minn = v[0];
	int maxn = p * minn;
//	for (auto it = v.end() - 1; it != v.begin() - 1; it--){
//			cout << *it << "  "; 
//	}
    int result = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + result; j < n; j++) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > result)
                    result = temp;
            } else {
                break;
            }
        }
    }
	cout << result;
	return 0;
}
