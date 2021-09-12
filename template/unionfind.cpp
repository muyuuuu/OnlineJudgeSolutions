#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> parent;
std::vector<int> root;
std::vector<int> tmp;

int find(int idx) {
    while (idx != parent[idx]) {
        parent[idx] = parent[parent[idx]];
        idx = parent[idx];
    }
    return idx;
}

void union_(int pa, int ch) {
    int f1 = find(pa);
    int f2 = find(ch);
    if (f1 != f2)
        parent[f1] = f2;
}

bool cmp(int a, int b) {
    return a > b;
}

int main (){
    int n, a, b;
    std::cin >> n;
    parent.resize(n + 1);
    root.resize(n + 1);
    tmp.assign(1005, 0);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d: ", &a);
        for (int j = 0; j < a; j++) {
            scanf("%d", &b);
            if (tmp[b] == 0)
                tmp[b] = i;
            union_(i, find(tmp[b]));
        }
    }
    
    int cnt{0};
    for (int i = 1; i <= n; i++) {
        root[find(i)] ++;
    }

    tmp.clear();
    
    for (int i = 1; i <= n; i++) {
        if (root[i] > 0)
            cnt++;
    }

    for (int i = 1; i <= n; i++) {
        if (root[i] > 0)
            tmp.push_back(root[i]);
    }

    std::cout << cnt << std::endl;
    std::sort(tmp.begin(), tmp.end(), cmp);
    
    int idx{0};
    for (auto& i: tmp) {
        if (idx == 0) {
            idx ++;
            std::cout << i;
        }
        else
            std::cout << " " << i;
    }

    return 0;
}
