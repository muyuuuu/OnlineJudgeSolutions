#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

char name[40010][5];
vector<int> course[2510];

bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for(int j = 0; j < cnt; j++) {
            // 读入课程号
            scanf("%d", &temp);
            // 课程号里有这个人
            course[temp].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        // 一个课的人数作为参数传入，比较人名的先后
        sort(course[i].begin(), course[i].end(), cmp1);
        for(int j = 0; j < course[i].size(); j++)
            printf("%s\n", name[course[i][j]]);
    }
    return 0;
}