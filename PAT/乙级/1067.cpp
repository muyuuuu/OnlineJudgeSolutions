#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string psd, temp;
    int n;
    cin >> psd >> n;
    int i = 0;
    getchar();
    while (i < n)
    {
        getline(cin, temp);
        if (temp == "#")
            break;
        i++;
        if (i <= n && temp != psd)
        {
            cout << "Wrong password: " << temp << endl;
        }
        if (temp != psd && i == n)
        {
            cout << "Account locked";
            break;
        }
        if (i <= n && temp == psd)
        {
            cout << "Welcome in";
            break;
        }   
    }
    return 0;
}
