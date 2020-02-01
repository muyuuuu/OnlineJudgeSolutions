#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int weight_sum;
int weight[101];
int temp_path[101];
int path_num;

vector<int> v[101];
vector<int> path[101];

void dfs(int index, int nodeNum, int sum_temp)
{
    if (sum_temp > weight_sum)
    {
        return ;
    }
    if(sum_temp == weight_sum) 
    {
        if (v[index].size() != 0)  // 不是叶子节点
        {
            return ;
        }
        else
        {   
            for (int i = 0; i < nodeNum; i++)
            {
                path[path_num].push_back(weight[temp_path[i]]);
            }
            path_num++;
            return ;
        }
    }
    for (int i = 0; i < v[index].size(); i++)
    {
        int node = v[index][i];
        temp_path[nodeNum] = v[index][i];
        dfs(node, nodeNum + 1, sum_temp + weight[v[index][i]]);
    }
}

int cmp(int a, int b)
{
    return weight[a] > weight[b];
}

int main()
{
    int n, non;
    cin >> n >> non >> weight_sum;
    int temp;
    int id, num, a;
    for (int j = 0; j < n; j++)
    {
        cin >> weight[j];
    }
    for (int i = 0; i < non; i++)
    {
        cin >> id >> num;
        for(int j = 0; j < num; j++)
        {
            cin >> a;
            v[id].push_back(a);
        }
        sort(v[id].begin(), v[id].end(), cmp);
    }    
    dfs(0, 1, weight[0]);
    for (int i = 0; i < 101; i++)
    {
        if (path[i].size() == 0)
            return 0;
        else
        {
            for(auto it = path[i].begin(); it != path[i].end(); it++)
            {
                cout << *it ;
                if (it != path[i].end() - 1 ) // 多输出了一个空格，全部错误
                    cout << " ";                
            }
        }
        if (path[i+1].size() != 0)
            cout << endl;
    }
    return 0;
}