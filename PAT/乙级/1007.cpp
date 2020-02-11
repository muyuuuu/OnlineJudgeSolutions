#include <iostream>
#include <cmath>

using namespace std;

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

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n ; i++)
    {
        if (i + 2 <= n)
            if (isprime(i) && isprime(i + 2))
                count ++;
    }
    cout << count;
    return 0;
}
