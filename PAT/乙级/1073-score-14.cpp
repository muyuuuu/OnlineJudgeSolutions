#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int id;
    float score;
    int num;
    string result;
    int count;
};

bool cmp(node a, node b)
{
    return a.id < b.id;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<node> ans;
    ans.resize(m);
    node temp; 
    int a;
    string str = "", temp1;
    vector<char> error[m];
    for (int i = 0; i < m; i++)
    {
        cin >> temp.score >> a >> temp.num;
        for (int j = 0; j < temp.num; j++)
        {
            cin >> temp1;
            str += temp1;
        }
        temp.result = str;
        temp.count = 0;
        temp.id = i + 1;
        str = "";
        ans[i] = temp;
    }    
    cin.get();
    str = "";
    int key = 0;
    float sum = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp1);
        for (int j = 0; j < temp1.length(); j++)
        {
            if (isdigit(temp1[j]))
            {
                for (int k = j + 2; k <= j + (temp1[j] - '0') * 2; k = k + 2)
                    str += temp1[k];
                if (str.length() > ans[key].result.length())
                {
                    ans[key].count++;           
                }
                if (str.length() == ans[key].result.length())
                {
                    if (str == ans[key].result)
                        sum += ans[key].score;
                    else
                        ans[key].count++;
                }
                if (str.length() < ans[key].result.length()) 
                {
                    for (int l = 0; l < str.length(); l++)
                        if (ans[key].result.find(str[l], 0) == string::npos)
                        {
                            if (flag == 0)
                                ans[key].count++;
                            flag = 1;
                        }
                    if (flag == 0)
                        sum += ans[key].score / 2;
                }
                for (int l = 0; l < str.length(); l++)
                {
                    if (ans[key].result.find(str[l], 0) == string::npos)
                        error[key].push_back(str[l]);
                }
                for (int l = 0; l < ans[key].result.length(); l++)
                {
                    if (str.find(ans[key].result[l], 0) == string::npos)
                        error[key].push_back(ans[key].result[l]);
                }                             
                str = "";
                key++;
                if (key == m)
                    key = 0;
            }
        }
        printf("%.1f\n", sum);
        sum = 0;
    }
    int max = -1;
    for (int i = 0; i < m; i++)
        if (ans[i].count >= max)    
            max = ans[i].count;

    if (max == 0)
    {
        cout << "Too simple";
        return 0;
    }

    vector<node> ans1;

    for (int i = 0; i < m; i++)
        if (ans[i].count == max)
            ans1.push_back(ans[i]);
    
    int arr[5] = {0};
    str = "";
    int max1 = 0;
    int count = 0;

    sort(ans1.begin(), ans1.end(), cmp);
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << max << " " << ans1[i].id;
        for (int j = 0; j < error[ans1[i].id - 1].size(); j++)
        {
            if (error[ans1[i].id - 1][j] - 'a' == 0)
                arr[0]++;
            if (error[ans1[i].id - 1][j] - 'b' == 0)
                arr[1]++;
            if (error[ans1[i].id - 1][j] - 'c' == 0)
                arr[2]++;
            if (error[ans1[i].id - 1][j] - 'd' == 0)
                arr[3]++;
            if (error[ans1[i].id - 1][j] - 'e' == 0)
                arr[4]++;                        
        }
        max1 = -1;
        for (int i = 0; i < 5; i++)
            if (arr[i] > max1)
                max1 = arr[i];
        for (int j = 0; j < 5; j++)
        {
            if (arr[j] == max1)
            {
                count++;
                if (count == 1)
                    cout << "-" << char(j + 'a') << endl;
                else
                    str += char(j + 'a');
            }
        }
        if (count >= 2)
            for (int j = 0; j < count - 1; j++)
                cout << max << " " << ans1[i].id << "-" << str[j] << endl;
        for (int j = 0; j < 5; j++)
            arr[j] = 0;
        count = 0;
        str = "";
        max1 = 0;
    }
    
    return 0;
}
