#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
void showvector(std::vector<T> v)
{
    // 因此，如果你想直接告诉编译器T::iterator是类型而不是变量，只需用typename修饰：
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}

int main()
{
    std::vector<string>  v6 = { "hi","my","name","is","lee" };
    v6.resize(3);  //重新调整vector容量大小
    showvector(v6);
    vector<int> v5 = { 1,2,3,4,5 }; //列表初始化,注意使用的是花括号
    cout << v5.front() << endl; //访问第一个元素
    cout << v5.back() << endl; //访问最后一个元素

    showvector(v5);
    v5.pop_back(); //删除最后一个元素
    showvector(v5);
    v5.push_back(6); //加入一个元素并把它放在最后
    showvector(v5);
    v5.insert(v5.begin()+1,9); //在第二个位置插入新元素
    showvector(v5);
    v5.erase(v5.begin() + 3);  //删除第四个元素
    showvector(v5);
    v5.insert(v5.begin() + 1, 7,8); //连续插入7个8
    showvector(v5);
    v5.clear(); //清除所有内容
    showvector(v5);
    return 0;
}