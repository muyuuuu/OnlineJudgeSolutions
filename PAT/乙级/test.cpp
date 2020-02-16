#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "0123456789";

    // 返回 [3] 及以后的子串
    cout<<str.substr(3)<<endl;
    // 返回 str[2]~str[2+(4-1)] 子串(即从[2]开始4个字符组成的字符串)
    cout<<str.substr(2, 4);
    if (str.find("aa1", 0) == string::npos)
    {
        cout << "找不到该子串！" << endl;
    }
    return 0;
}