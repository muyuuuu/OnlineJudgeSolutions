#include <iostream>
#include <vector>
#include <set>
using namespace std;

int bird[10001] = {0};
vector<int> father, isRoot;
set<int> s;

int find(int x){
	int a = x;
	while (x != father[x])
		x = father[x];
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;	
	}
	return x;
}


void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA != faB) father[faA] = faB;
}

int main(){
	int n; scanf("%d", &n);
	father.resize(n + 1);
	isRoot.resize(n + 1);
	for (int i = 1; i <= n; i++)
		father[i] = i;
	int a, b;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a);
		for (int j = 0; j < a; j++){
			scanf("%d", &b);
			if (bird[b] == 0){
				s.insert(b);
				bird[b] = i;
			}
			Union(i, find(bird[b]));
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
        isRoot[find(i)]++;
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) cnt++;
    }
    cout << cnt << " " << s.size() << endl;
    int n1; scanf("%d", &n1);
    for (int i = 0; i < n1; i++){
    	scanf("%d %d", &a, &b);
    	if (find(bird[a]) == find(bird[b]))
    		cout << "Yes" << endl;
    	else 
    		cout << "No" << endl;
	}
	return 0;
} 

