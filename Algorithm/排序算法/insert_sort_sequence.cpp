#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[10] = {3, 5, 4, 7, 1, 6, 8, 5, 9, 2};
    int len = 10;
    int temp;
    for (int i = 1; i < len; i++)
    {
        cout << "Remove " << arr[i] << " : ";
        if (arr[i] >= arr[i - 1]){
            for (int j = 0; j < len; j++)
                cout << arr[j] << "  ";
            cout << endl;
            continue;
        }
        else{
            temp = arr[i];
            int k = i;
            for (int j = i - 1; j >= 0; j--){
                if (arr[j] <= arr[i] || (j == 0 && arr[j] > arr[i])){   
                    if (j == 0 && arr[j] > arr[i]) 
                        j = -1;
                    while (k > j + 1){
                        arr[k] = arr[k - 1];
                        k--;
                    }
                    arr[j + 1] = temp;
                    break;
                }
            }
        }
        for (int j = 0; j < len; j++)
            cout << arr[j] << "  ";
        cout << endl;
    }
    return 0;
}
