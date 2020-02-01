#include <iostream>

using namespace std;

int main(){
	string str1, str2, str3, str4;
	cin >> str1; cin >> str2; cin >> str3; cin >> str4;
//	cout << str2;
	int day, hour, pos = 0; 
	int len = str1.length() > str2.length() ? str2.length() : str1.length();
	for (int i = 0 ; i < len; i++){
		if (str1[i] == str2[i]){
			if (str1[i] >= 'A' && str1[i] <= 'G' ){
				day = (str1[i] - 'A' + 1);
				pos = i + 1;
				break;
			}
		}
	}
	for (int i = pos; i < len; i++){
		if (str1[i] == str2[i]){
			if ((str1[i] >= 'A' && str1[i] <= 'N') || isdigit(str1[i]) ){
//				cout << str1[i] << "---" << endl;
				if (str1[i] >= 'A' && str1[i] <= 'N'){
					hour = (str1[i] - 'A' + 10); break;
				} 
				if ( isdigit(str1[i])){
					hour = (str1[i] - '0'); break;
				}
			}
		}
	}
	switch (day){
		case 1 : cout << "MON "; break;
		case 2 : cout << "TUE "; break;
		case 3 : cout << "WED "; break;
		case 4 : cout << "THU "; break;
		case 5 : cout << "FRI "; break;
		case 6 : cout << "SAT "; break;
		case 7 : cout << "SUN "; break;
	}
	printf("%02d", hour);
	int j = 0;
    while (j < str3.length() && j < str4.length()) {
        if (str3[j] == str4[j] && isalpha(str3[j])) {
            pos = j;
            break;
        }
        j++;
    }
    cout << ":";
    printf("%02d", pos);
	return 0;
} 
