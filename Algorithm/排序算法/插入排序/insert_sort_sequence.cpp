#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int arr[1000002] = {0};

int main(int argc, char const *argv[])
{
    int len = 0;

    string path = "Five_hundred_thousand.txt";
    string out = "Five_hundred_thousand_seq.txt";
    
    ifstream in(path.c_str());
    ofstream ou(out.c_str());
    
    if (!in.is_open())
    {
        cerr << "open file failed!" << endl;
        exit(-1);
    }

    if (!ou.is_open())
    {
        cerr << "create file failed!" << endl;
        exit(-1);
    }
    
    int a = 0;
    while (in >> a)
        arr[len++] = a;
    
    int temp;
    clock_t start = clock();
    for (int i = 1; i < len; i++)
    {
        if (arr[i] >= arr[i - 1]){
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
    }
    clock_t end   = clock();
    cout <<  (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    in.close();
    for (int i = 0; i < len; i++)
        ou << arr[i] << endl;
    ou.close();
    return 0;
}
