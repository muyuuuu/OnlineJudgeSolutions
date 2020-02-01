#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	getline(cin, str);
	int a[26]={0};
	for (int i = 0; i < str.size(); ++i)
	{
		str[i] = tolower(str[i]);
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if (islower(str[i]))
			a[str[i]-'a']++;
	}
	int max = a[0], t = 0;
    for (int i = 1; i < 26; i++) {
        if (a[i] > max) {
            max = a[i];
            t = i;
        }
    }
    printf("%c %d", t + 'a', max);
    return 0;
}