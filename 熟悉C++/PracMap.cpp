#include <map>
#include <string>
#include <iostream>

using namespace std;

void showmap(map<string, int> v)
{
    for (map<string, int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->first << "  " << it->second << endl;  //注意用法，不是用*it来访问了。first表示的是key，second存的是value
    }
    cout << endl;
}

int main()
{
    map<string, int> m1; //<>里的第一个参数表示key的类型,第二个参数表示value的类型
    m1["Kobe"] = 100;
    m1["James"] = 99;
    m1["Curry"] = 98;

    string s("Jordan");
    m1[s] = 90;

    cout << m1["Kobe"] << endl;
    cout << m1["Jordan"] << endl;
    cout << m1["Durant"] << endl; //不存在这个key，就显示0

    m1.erase("Curry");//通过关键字来删除
    showmap(m1);
    // pair 的意思是将两个数据组合成一个数据
    m1.insert(pair<string, int>("Harris", 89)); //也可以通过insert函数来实现增加元素
    showmap(m1);
    m1.clear(); //清空全部

    return 0;
}
