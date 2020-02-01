#include <cstdio>
using namespace std;
int pre[] = {1, 2, 3, 4, 5, 6};
int in[] = {3, 2, 4, 1, 6, 5};
void post(int root, int start, int end) {
    if(start > end) 
        return ;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    post(root + 1, start, i - 1);
    post(root + 1 + i - start, i + 1, end);
    printf("%d ", root);
}

int main() {
    post(0, 0, 5);
    return 0;
}