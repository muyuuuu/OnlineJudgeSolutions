#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct NODE {
    int address, key, next, num = 2 * maxn;
}node[maxn];
bool exist[maxn];
int cmp1(NODE a, NODE b){
    return a.num < b.num;
}
int main() {
    int begin, n, cnt1 = 0, cnt2 = 0, a;
    scanf("%d%d", &begin, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        scanf("%d%d", &node[a].key, &node[a].next);
        node[a].address = a;
    }
    // 算法时间复杂度 O(n)
    for(int i = begin; i != -1; i = node[i].next) {
        // 没有访问直接添加进来
        if(exist[abs(node[i].key)] == false) {
            exist[abs(node[i].key)] = true;
            // cnt 表明了链表的顺序
            node[i].num = cnt1;
            cnt1++;
        }
        else {
            node[i].num = maxn + cnt2;
            cnt2++;
        }
    }
    sort(node, node + maxn, cmp1);
    int cnt = cnt1 + cnt2;
    for(int i = 0; i < cnt; i++) {
        if(i != cnt1 - 1 && i != cnt - 1) {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
        } else {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }
    return 0;
}