#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector <int> v(0);
    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    temp = 0;
    // cout << N << "  " << M << "  " << endl;
    // for (int i = 0; i < N; i++)
    //     cout << v[i] << endl;
    
    return 0;
}