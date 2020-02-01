#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double p, r;
double level = 100005;

int num = 0;

vector <int> v[100005];

void dfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        if (depth == level)
        {
            num ++ ;
        }
        if (depth < level)
        {
            level = depth;
            num = 1;
        }
    }
    for (int i = 0; i < v[index].size(); i++)
       dfs(v[index][i], depth + 1);
}

int main()
{
    int n;
    cin >> n >> p >> r;
    r = r / 100;
    int temp, temp1;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp != 0)
        {
            for (int j = 0; j < temp; j++)
            {
                cin >> temp1;
                v[i].push_back(temp1);
            }
        }
    }
    dfs(0, 0);
    printf ("%.4f", p * pow(1 + r, level)); 
    cout << " " << num;
    return 0;
}