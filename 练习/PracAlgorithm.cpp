// 排序
// 最大最小求和
// 填充
// 逆序
// 交换
// 长度
// 迭代器
// 迭代器是一种检查容器内元素并遍历元素的数据类型。可以替代下标访问vector对象的元素。
// 每种容器类型都定义了自己的迭代器类型，如 vector：
// 每种容器都定义了一对命名为 begin 和 end 的函数，用于返回迭代器。如果容器中有元素的话，由 begin 返回的迭代器指向第一个元素：

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>

using namespace std;

int main()
{
	// 字符串长度
	string str("0123");
	int string_len = str.length();
	
	// 不定长数组长度
	// size是当前vector容器真实占用的大小，也就是容器当前拥有多少个容器。
	// capacity是指在发生realloc前能允许的最大元素数，即预分配的内存空间。
	vector<int> v5 = { 4,2,3,4};
	// 求长度
	int vector_len = v5.size();
	// 求最大值
	vector<int>::iterator p = max_element(v5.begin(), v5.end());
	cout<<*p<<endl;
	// 求最小值
	vector<int>::iterator q = min_element(v5.begin(), v5.end());
	// cout<<*q<<endl;
	// 求最大值索引
	int position = std::distance(v5.begin(), p);
	cout<<position<<endl;
	cout<<v5[position]<<endl;
	// 求和，0表示计算的初始值
	int sum = accumulate(v5.begin(), v5.end(), 0);
	// cout<<sum<<endl;
	// 求均值
	// cout<<sum/vector_len<<endl;

	// 交换
	vector<double> v1 = { 1,2,3,4};
	swap(v1[0], v1[2]);
	// 排序
	sort(v1.begin(), v1.end());
	// 填充
	vector <int> V;	
	V.resize(20);
	fill(V.begin()+0,V.begin()+10,5);



	list<int> l1{ 1,2,3,4,5,5,6,7,7 };
	int list_len = l1.size();


	return 0;
}