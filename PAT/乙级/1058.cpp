#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int score;
    int num;
    int correct;
    vector<char> check;
    int error;
};

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<node> v;
    vector<char> a;
    v.resize(m);
    char temp1;
    string temp;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].score >> v[i].num >> v[i].correct;
        for (int j = 0; j < v[i].correct; j++)
        {
            cin >> temp1;
            v[i].check.push_back(temp1);
            v[i].error = 0;
        }
        // cout << v[i].correct << "--" << v[i].check.size() << endl;
    }     
    int key = 0, sum = 0, flag = 0;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        getline(cin, temp);
        // cout << temp << "----" << endl;
        key = 0;
        for (int k = 0; k < temp.length(); k++)
        {
            if (isdigit(temp[k]))
            {
                // cout << "here" << endl;
                // a.clear();
                a.resize(0);
                // cout << a.size() << endl;
                for (int j = k + 2; j <= k + 2*(temp[k] - '0'); j+=2)
                {
                    a.push_back(temp[j]);
                }
                // 开始判断
                if (a.size() == v[key].correct)
                {
                    // cout << "here" << endl;
                    for (int j = 0; j < a.size(); j++)
                    {
                        if (a[j] != v[key].check[j])
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        sum += v[key].score;
                    }
                    else
                    {
                        v[key].error++;
                    }
                }
                else
                {
                    v[key].error++;
                }
                key++;
            }
            flag = 0;
        }
        cout << sum << endl;
    }
    int max = -1;
    for (int i = 0; i < m; i++)
    {
        if (v[i].error > max)
            max = v[i].error;
    }
    if (max == 0)
    {
        cout << "Too simple";
        return 0;
    }
    cout << max << " ";
    flag = 0;
    for (int i = 0; i < m; i++)
    {
        if (v[i].error == max)
        {
            if (flag == 0)
            {
                flag = 1;
                cout << i + 1;
            }
            else
                cout << " " << i + 1; 
        }
    }
    return 0;
}
