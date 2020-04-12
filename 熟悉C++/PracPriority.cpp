/*** 
 * @Author         : lanling
 * @Date           : 2020-04-12 14:35:49
 * @LastEditTime: 2020-04-12 14:43:03
 * @FilePath       : \熟悉C++\PracPriority.cpp
 * @Github         : https://github.com/muyuuuu
 * @Description    : 
 * @佛祖保佑，永无BUG
 */


#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> p;
	p.push(1);
	p.push(2);
	p.push(8);
	p.push(5);
	p.push(43);
    // 优先输出大的数据
	for(int i = 0; i < 5; i++)
    {
		cout << p.top() << endl;
		p.pop();
	}
    // 优先输出小的数据
	priority_queue<int, vector<int>, greater<int> >p;
    //降序队列 优先输出大的元素
    // priority_queue <int, vector<int>, less<int> >q;
	p.push(1);
	p.push(2);
	p.push(8);
	p.push(5);
	p.push(43);
	for(int i = 0; i < 5; i++)
    {
		cout << p.top() << endl;
		p.pop();
	}
	return 0;
}
