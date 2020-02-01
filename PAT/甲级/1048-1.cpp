#include <iostream>
using namespace std;
int a[1001];
// Segmentation Fault：有2中情况可能导致次错误：
// buffer overflow -- 缓冲区溢出，也就是你访问 了非法内存，比如你神情了一个大小为2的数组a，却访问了a[10000]，或者在C/C++中访问了空指针等等。
// stack overflow -- 堆栈溢出，有可能你在c/c++程序的函数中申请了过大的空间，或者递归层次太多，导致堆栈溢出了。
// 这个时候只能换种思路了
int main() {
    int n, m, temp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a[temp]++;
    }
    for(int i = 0; i < 1001; i++) {
        if(a[i]) {
            a[i]--;
            if(m > i && a[m-i]) {
                printf("%d %d", i, m - i);
                return 0;
            }
            a[i]++;
        }
    }
    printf("No Solution");
    return 0;
}