#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <array>

using namespace std;

array<int, 100005> arr{0};
int main(){

    int n, m, t1, t2;
    cin >> n;
    map<int, int> cp;
    vector<int> v(0);

    for (int i = 0; i < n; i++){
        cin >> t1 >> t2;
        if (t1 == 0) t1 = 100001;
        if (t2 == 0) t2 = 100001;
        cp[t1] = t2;
        cp[t2] = t1;
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> t1;
        if (t1 == 0) t1 = 100001;
        v.push_back(t1);
        arr[t1] = 1;
    }

    set<int> s;
    int flag{0}, cnt{0};
    for (int i = 0; i < v.size(); i++){
        if (arr[v[i]] == 1 && arr[cp[v[i]]] == 1 && cp[v[i]] != 0)
            continue;
        else{
            s.insert(v[i]);
            cnt ++;
        }
    }
    cout << cnt << endl;
    for (auto it = s.begin(); it != s.end(); it++){
        if (flag == 0){
            flag = 1;
            printf("%05d", *it);
        }
        else
            printf(" %05d", *it);
    }

    return 0;
}