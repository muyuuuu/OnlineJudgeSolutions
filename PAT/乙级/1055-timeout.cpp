#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	string name;
	int height;
};

vector<node> v;

int cmp(node a, node b)
{
	return a.height != b.height ? a.height > b.height : a.name < b.name;
}

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	node temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp.name >> temp.height;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	// 每排的人数
	int num = (n - (n % k)) / k;
	if (num == 1)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i].name << endl;
		return 0;
	}
	// 最后一排的人数
	int num1;
	k == 1 ? num1 = n : num1 = n - (k - 1) * num;
	int value = (num1 / 2) * 2 - 1;
	while (value > 0)
	{
		cout << v[value].name << " ";
		value -= 2;
	}
	int right;
	num1 % 2 == 0 ? (right = num1 / 2) : (right = num1 / 2 + 1);	
	for (int j = 0; j < right * 2; j+= 2)
		j == 0 ? cout << v[j].name : cout << " " << v[j].name;
	// 删除追后一排的人
	if (k == 1) return 0;
	for (int i = 0; i < num1; i++)
		v.erase(v.begin() + 0);
	// 一共几排
	cout << endl;
	int row = n / k - 1;
	for (int i = 0; i < row; i++)
	{
		value = (num / 2) * 2 - 1;
		while (value > 0)
		{
			cout << v[value].name << " ";
			value -= 2;
		}
		num % 2 == 0 ? right = num / 2 : right = num / 2 + 1;	
		for (int j = 0; j < right * 2; j+= 2)
			j == 0 ? cout << v[j].name : cout << " " << v[j].name;
		cout << endl;
		for (int i = 0; i < num; i++)
			v.erase(v.begin() + 0);
	}
	return 0;
}
