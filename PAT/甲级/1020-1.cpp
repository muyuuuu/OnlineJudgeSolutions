#include <cstdio>
using namespace std;
int post[] = {3, 4, 2, 6, 5, 1};
int in[] = {3, 2, 4, 1, 6, 5};
void pre(int root, int start, int end) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    printf("%d ", post[root]);
    // root - 1
    // end - i 是右子树的数量，root - 1 - end + i是左子树的数量
    // 最左边的位置就是树根
    pre(root - 1 - end + i, start, i - 1);
    pre(root - 1, i + 1, end);
}

int main() {
    pre(5, 0, 5);
    return 0;
}