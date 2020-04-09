#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int book[50001];

struct node 
{
    int value;
    int cnt;
};

int cmp(node a, node b)
{
    return a.cnt != b.cnt ? a.cnt > b.cnt : a.value < b.value;
}

int main() 
{
    int n, k, num;
    scanf("%d%d", &n, &k);
    vector<node> s;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &num);
        if (i != 0) 
        {
            printf("%d:", num);
            int tempCnt = 0;
            sort(s.begin(), s.end(), cmp);
            for(int i = 0; i < s.size() && tempCnt < k; i++) 
            {
                printf(" %d", s[i].value);
                tempCnt++;
            }
            printf("\n");
        }
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j].cnt == book[num] && s[j].value == num)
            {
                s.erase(s.begin() + j);
                break;
            }
        }
        book[num]++;
        s.push_back(node{num, book[num]});
    }
    return 0;
}