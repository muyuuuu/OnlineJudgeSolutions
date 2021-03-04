#include<iostream> 
#include <string>
using namespace std; 
int main()
{
    string str("cvicses");
    string s(str.rbegin(), str.rend());
    cout << s <<endl;
    return 0;
}