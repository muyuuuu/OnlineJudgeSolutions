#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;
    string id = "0", in, out;
    string ID1, ID2, IN = "24:59:59", OUT = "00:00:00";
    for (int i = 0; i < m; i++)
    {
        cin >> id >> in >> out;
        if (in <= IN)
        {
            IN = in;
            ID1 = id;
        }
        if (out >= OUT)
        {
            OUT = out;
            ID2 = id;
        }
    }
    cout << ID1 << " " << ID2;
}