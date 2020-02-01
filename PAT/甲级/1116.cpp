#include <iostream>
#include <cmath>

using namespace std;

struct node
{
	string value;
	bool flag;
};

node arr[10004];

int isprime(int n) 
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

int main()
{
	string a;
	int n;
	int key = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		arr[key++].value = a;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> a; int tag = 1;
		for (int j = 0; j < key; j++)
		{
			if (arr[j].value == a)
			{
//				tag = 1;
				if (j == 0) 
				{
					if (arr[j].flag == false)
					{
						cout << arr[j].value << ": Mystery Award" << endl;
						arr[j].flag = true; tag = 0;
						continue;
					}
					else { cout << arr[j].value << ": Checked" << endl; tag = 0; continue; }
				}
				if (isprime(j + 1))
				{
					if (arr[j].flag == false)
					{
						cout << arr[j].value << ": Minion" << endl; tag = 0; 
						arr[j].flag = true; continue;
					}
					else {cout << arr[j].value << ": Checked" << endl; tag = 0; continue;}
				}
				else { cout << arr[j].value << ": Chocolate" << endl; tag = 0; continue;}
			}
			if (tag == 1 && j == key - 1)
			{
				cout << a << ": Are you kidding?" << endl; 
			}
		}
	}
	return 0;
}
