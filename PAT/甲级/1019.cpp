#include <iostream>

using namespace std;

int arr[40];

int main()
{
    int a, radix;
    int index = 0;
    cin >> a >> radix;
    while (a != 0)
    {
        arr[index++] = a % radix;
        a = a / radix;
    }
    int flag = 0;
	for(int i = 0; i < index / 2; i++) 
    {
		if(arr[i] != arr[index-i-1]) 
        {
			printf("No\n");
			flag = 1;
			break;
		}
	}
    if(!flag) printf("Yes\n");
    for(int i = index - 1; i >= 0; i--) {
		printf("%d", arr[i]);
		if(i != 0) 
            printf(" ");
	}
    return 0;
}