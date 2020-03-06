#include <iostream>
#include <vector>

using namespace std;

struct node
{
    string id;
    string psd;
};

vector <node> v;

int main(int argc, char const *argv[])
{
    int n, flag = 0;
    string str1, str2, str3;
    cin >> n;
    node temp;
    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2;
        str3 = str2;
        for (int j = 0; j < str2.length(); j++)
        {
            if (str2[j] == '1') str2[j] = '@';
            else if (str2[j] == '0') str2[j] = '%';
            else if (str2[j] == 'l') str2[j] = 'L';
            else if (str2[j] == 'O') str2[j] = 'o';
        }
        if (str2 != str3) 
        {
            flag++;
            temp.id = str1;
            temp.psd = str2;
            v.push_back(temp);
        }
    }
    if (flag != 0)
    {
        cout << flag << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].id << " " << v[i].psd << endl;
        }
    }
    else
    {
        if (n == 1)
            cout << "There is " << n << " account and no account is modified";
        else
            cout << "There are " << n << " accounts and no account is modified";
    }
    return 0;
}
