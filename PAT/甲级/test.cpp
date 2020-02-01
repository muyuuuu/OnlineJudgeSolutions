#include <iostream>

using namespace std;

int main(){
	int a = 12, b = 13;
	int max = a > b ? a : b; 

	do
    {
        if (max % a == 0 && max % b == 0)
        {
            cout << "LCM = " << max;
            break;
        }
        else
            ++max;
    } while (true);

	return 0;
}

