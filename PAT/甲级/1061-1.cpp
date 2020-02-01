#include <iostream>

using namespace std;

int main(){
	string str1, str2, str3, str4;
	cin >> str1; cin >> str2; cin >> str3; cin >> str4;
//	cout << str2;
	int day, flag = 1, hour; 
	int len = str1.length() > str2.length() ? str2.length() : str1.length();
	for (int i = 0 ;i < len; i++){
		if (str1[i] == str2[i]){
			if (str1[i] >= 'A' && str1[i] <= 'G' && flag == 1){
				day = (str1[i] - 'A' + 1);	flag++; continue; // Êèºö 
			}
			if ((flag == 2 && str1[i] >= 'A' && str1[i] <= 'N') || (flag == 2 && isdigit(str1[i]))){
				if (( str1[i] >= 'A' && str1[i] <= 'N')){
//					cout << str1[i] << "---" << endl;
					hour = (str1[i] - 'A' + 10); flag++; break;
				} 
				if (isdigit(str1[i])){
					flag++; hour = (str1[i] - '0'); break;
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
	printf("%02d", hour);cout << ":";
	int j = 0, pos;
    while (j < str3.length() && j < str4.length()) {
        if (str3[j] == str4[j] && isalpha(str3[j])) {
            pos = j;
            break;
        }
        j++;
    }
    printf("%02d", pos);
	return 0;
} 
