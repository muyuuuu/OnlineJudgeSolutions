#include <iostream>
#include <cmath>

using namespace std;

struct node
{
	int index;
	bool flag;
};

node arr[10004];

int isprime(int n) 
{ 
	if (n < 2)
		return 0;
	for (int i = 2; i <= (int) sqrt((double) n); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n; cin >> n; int a;
	for (int i = 0; i < n; i++){
		scanf("%d", &a);
		arr[a].index = i + 1;
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		int tag = 1;
		scanf("%d", &a);
		if (arr[a].index == 1 ){
			if(arr[a].flag == false){
				printf("%04d%s\n", a, ": Mystery Award");
				arr[a].flag = true; tag = 0;
				continue;	
			}
			else{
				printf("%04d%s\n", a, ": Checked"); tag = 0;
				continue;
			}
		}
		if (isprime(arr[a].index) && arr[a].index > 0){
			if (arr[a].flag == false){
				printf("%04d%s\n", a, ": Minion"); tag = 0;
				arr[a].flag = true; continue;
			}
			else{
				printf("%04d%s\n", a, ": Checked"); tag = 0;
				continue;
			}
		}
		else if (arr[a].index > 0){ 
			if (arr[a].flag == false ){
				printf("%04d%s\n", a, ": Chocolate"); 
				tag = 0; continue;
			}
			else {
				printf("%04d%s\n", a, ": Checked"); tag = 0;
				continue;
			}
		}
		if (tag == 1){
			cout << a << ": Are you kidding?" << endl; 
		}
	} 
	return 0;
}

