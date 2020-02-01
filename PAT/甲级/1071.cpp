#include<iostream>
#include<map>
#include<algorithm>
#include <string.h>

using namespace std;

map<string, int> word;

void print_map(map<string, int> &word)
{
    int max = -2;
    string str;
    for (auto it = word.begin(); it != word.end(); it++)
    {
        if (it->second > max)
        {
            max = it->second;
            str = it->first;
        }
    }    
    cout << str << " " << max;
}

int main()
{
    char c;
    string str = "";
    cin.get(c);
    while( c != '\n' )
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = tolower(c);
            }
            str.push_back(c);
        }
        else
        {
            if (str.length() != 0)
                word[str]+=1;
            str = "";
        }
        cin.get(c);
        if (c == '\n' && str.length() != 0)
        {
            word[str]+=1;
        }
    }
    print_map(word);
    return 0;
}