#include <iostream>

using namespace std;

int method = 0;
int N = 0;
int bad[1001] = {0};

void up(int n){
    // if (n >= N){
        if (n == N){
            method ++;
            return;
        }
    // }
    if (n < N && !bad[n]){
        up(n+1);
        up(n+2);
        up(n+3);
    }
    return;
}

int main(){
    int k;
    cin >> N >> k;
    int a;
    for (int i = 0; i < k; i++){
        cin >> a; 
        bad[a] = 1;
    }
    up(0);
    cout << method;
    return 0;
}