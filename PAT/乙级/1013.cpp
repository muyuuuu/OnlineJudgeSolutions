#include <iostream>
#include <cmath>

using namespace std;

int arr[10004] = {0};

int prime(int n) 
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

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int count = 1;
    int flag = 1;
    int key = 0;
    while (count <= m)
    {
        for (int i = flag; i < flag + 10000; i++)
        {
            if (prime(i))
            {
                if (count >= n && count <= m)
                    arr[key++] = i;
                flag = i + 1;
                break;
            }
        }
        count++;
    }
    int temp = 0;
    for (int i = 0; i < key; i++)
    {
        if (temp == 0)
        {
            cout << arr[i];
            temp++;
        }
        else
        {
            cout << " " << arr[i];
            temp++;
            if (temp == 10)
            {
                cout << endl;
                temp = 0;
            }
        }
    }
    return 0;
}
