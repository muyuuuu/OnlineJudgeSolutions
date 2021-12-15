- [队列](#队列)
  - [剑指 Offer 59 - II. 队列的最大值](#剑指-offer-59---ii-队列的最大值)
  - [剑指 Offer 62. 圆圈中最后剩下的数字](#剑指-offer-62-圆圈中最后剩下的数字)

# 队列

## 剑指 Offer 59 - II. 队列的最大值

这个解法比较笨拙，但是我能接受的解。首先压入队列的时候，除了将队列压入朴素队列外，还需要压入优先级队列，并记录每个元素出现的次数，弹出的时候元素出现次数递减。这样在取最大值的时候，先判断优先级队列的最大值是否存在与队列中，如果存在，去除优先级队列的最大值，否则，优先级队列弹出，直到最大的元素的出现次数比 0 大。

```cpp
class MaxQueue {
public:
  priority_queue<int> pq;
  unordered_map<int, int> m;
  deque<int> q;
  MaxQueue() {

  }
  
  int max_value() {
    if (q.size() == 0)
      return -1;
    while (q.size() && pq.size() && m[pq.top()] == 0) {
      pq.pop();
    }
    int a = pq.top();
    return a;
  }
  
  void push_back(int value) {
    q.push_back(value);
    pq.push(value);
    m[value]++;
  }
  
  int pop_front() {
    if (q.size() == 0)
      return -1;
    int a = q.front();
    q.pop_front();
    m[a]--;
    return a;
  }
};
```

## 剑指 Offer 62. 圆圈中最后剩下的数字

传说中的约瑟夫环问题，当时还想着模拟，结果发现超时了。后来看答案，这种找规律题没啥意思...

```cpp
class Solution {
public:
  int lastRemaining(int n, int m) {
    int x = 0;
    for (int i = 2; i <= n; i++) {
      x = (x + m) % i;
    }
    return x;
  }
};
```