#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<string, int> stu;

int prime(int n) 
{ 
    if (n < 2)
        return 0;
    for (int i = 2; i <= (int) sqrt((double) n); i++) 
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int key = 1;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        stu[str] = key;
        key++;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> str;
        if (stu[str] == 0)
            cout << str << ": Are you kidding?" << endl;
        else if (stu[str] == 1)
        {
            cout << str << ": Mystery Award" << endl;
            stu[str] = -1;
        }
        else if (prime(stu[str]))
        {
            cout << str << ": Minion" << endl;
            stu[str] = -1;
        }
        else if (stu[str] == -1)
            cout << str << ": Checked" << endl;
        else
        {
            cout << str << ": Chocolate" << endl;
            stu[str] = -1;
        } 
    }
    return 0;
}
