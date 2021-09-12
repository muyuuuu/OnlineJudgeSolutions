#include <iostream>
#include <vector>

std::vector<int> tmp;
std::vector<int> parent;

int find(int x) {
    while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void union_(int p1, int p2) {
    int a = find(p1);
    int b = find(p2);
    if (a != b)
        parent[b] = a;
}

bool query(int p1, int p2) {
    int a = find(p1);
    int b = find(p2);
    if (a == b)
        return true;
    return false;
}

int main (){
    int n, a, b, c;
    std::cin >> n;

    tmp.assign(1005, 0);
    parent.resize(n);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> a;
        for (int j = 0; j < a; j++) {
            std::cin >> b;
            if (tmp[b] == 0)
                tmp[b] = i;
            union_(i, find(tmp[b]));
        }
    }

    std::cin >> a;
    for (int i = 0; i < a; i++) {
        std::cin >> b >> c;
        if (query(b, c))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }

}
