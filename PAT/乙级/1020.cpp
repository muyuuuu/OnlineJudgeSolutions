// 3 20
// 18 15 10
// 75 72 45
#include "iostream"
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int cla, num;
	scanf("%d%d", &cla, &num);
	vector<float> sto, cost;
	vector<float> pri;
	float money = 0;
	int j = 0;
	for (int i = 0; i < cla; ++i)
	{
		cin>>j;
		sto.push_back(j);
	}
	for (int i = 0; i < cla; ++i)
	{
		cin>>j;
		cost.push_back(j);
	}
	for (int i = 0; i < cla; ++i)
	{
		pri.push_back(cost[i] / sto[i]);
	}

	int position=0;
	if (num > accumulate(sto.begin(), sto.end(), 0))
	{
		money = accumulate(cost.begin(), cost.end(), 0);
	}
	else if (num == 0)
	{
		money = 0.00;
	}
    else
    {
        while(num > 0)
        {
            vector<float>::iterator max = max_element(pri.begin(), pri.end());
            position = std::distance(pri.begin(), max);
            // if (num == 0)
                // break;
            if (num - sto[position] >= 0)
            {
                num -= sto[position];
                money += cost[position];
                pri.erase(pri.begin() + position);
                sto.erase(sto.begin() + position);
                cost.erase(cost.begin() + position);
                continue;
            }
            if (num - sto[position] < 0)
            {
                money += (num) * pri[position];
                // num -= sto[position];
                break;
            }
        }
    }

	printf("%.2f", money);
	return 0;
}