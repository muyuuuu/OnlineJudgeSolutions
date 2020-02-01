#include <iostream>
#include <map>
#include <set>

using namespace std;

map<string, set<int> > title, author, key, pub, year;

void query(map<string, set<int> > &m, string &str) {
    if(m.find(str) != m.end()) {
        for(auto it = m[str].begin(); it != m[str].end(); it++)
            printf("%07d\n", *it);                         // *it表示映射的值 
    } else
        cout << "Not Found\n";
}

int main() {
    int n, m, id, num;
    scanf("%d", &n);                                       // n和块
    string ttitle, tauthor, tkey, tpub, tyear;
    for(int i = 0; i < n; i++) {
        scanf("%d\n", &id);                                // 读入ID
        getline(cin, ttitle);                              // 读入书名
        title[ttitle].insert(id);                          // title 是 map， ttitle是索引字
        getline(cin, tauthor);
        author[tauthor].insert(id);                        // 作者也插入ID
        while(cin >> tkey) {
            key[tkey].insert(id);
            char c = getchar();
            if(c == '\n') break;
        }
        getline(cin, tpub);
        pub[tpub].insert(id);
        getline(cin, tyear);
        year[tyear].insert(id);                            // 所用映射都插入ID 
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if(num == 1) query(title, temp);
        else if(num == 2) query(author, temp);
        else if(num == 3) query(key, temp);
        else if(num == 4) query(pub,temp);
        else if(num ==5) query(year, temp);
    }
    return 0;
}