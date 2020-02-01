#include <iostream>

using namespace std;

// 如果m大于n，那么循环右移m位相当于循环右移m%n位，因为那些n倍数位的移动是多余的，所以在使用m之前，先将m = m%n）

int main()
{
	int len, num;
	cin >> len >> num;
	num = num % len;
	int arr[len];
	for (int i = 0; i < len; i++)
	{
		cin>>arr[i];
	}
	int arr1[len];
	for (int i = 0; i < len; i++)
	{
		if (i < num)
			arr1[i] = arr[len-num+i];
		if (i >= num)
			arr1[i] = arr[i-num];
	}
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (flag == 0)
		{
			printf("%d", arr1[i]);
			flag = 1;
		}
		else
			printf(" %d", arr1[i]);
	}
	return 0;
}