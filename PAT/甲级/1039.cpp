#include<iostream>
#include<map>
#include<set>
using namespace std;

map<string, set<int> > name;

void print_query(string str, int flag)
{
    cout << str << " " ;
    cout << name[str].size();
    for(auto it = name[str].begin(); it != name[str].end(); it++)
    {
        printf(" %d", *it);  
    }
    if (flag == 0)
        cout << endl;   
}

int main()
{
    int n, k;
    cin >> n >> k;
    int flag = 0;
    for (int i = 0; i < k; i++)
    {
        int course, temp;
        string str;
        cin >> course >> temp;
        for (int j = 0; j < temp; j++)
        {
            cin >> str; // 不能scanf
            name[str].insert(course);
        }
    }
    string query;
    cin.get();
    getline(cin, query);
    string temp = "";
    for (int i = 0; i < query.length(); i++)
    {
        if (query[i] != ' ')
        {
            temp += query[i];
        }
        else
        {
            print_query(temp, flag);
            temp = "";
        }
        if (i == query.length() - 1) 
        {
            flag = 1;
            print_query(temp, flag);
        }
    }
    return 0;
}