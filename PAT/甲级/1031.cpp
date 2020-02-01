#include <iostream>

using namespace std;

void display_blank(int y){
	for (int i = 0; i < y - 2; i++)
		printf(" ");
	return ;
}

int main(){
	string str;
	cin >> str;
	int len = str.length();
	int x, y;
	x = (len + 2 ) / 3;
	y = len + 2 - x * 2;
	for (int i = 0; i < len; i++){
		if (i >= x - 1 && i <= x + y - 2){
			printf("%c", str[i]);
			continue;
			if (i == x + y - 2) break;
		}
		if (i < x - 1 ){
			printf("%c", str[i]); 
			display_blank(y);
			printf("%c\n", str[len-1-i]);	
		}
	}
	return 0;
}
