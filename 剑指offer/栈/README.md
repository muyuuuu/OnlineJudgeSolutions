# 栈

## 剑指 Offer 09. 用两个栈实现队列

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

这个题比较经典，用栈模拟队列。队列是先入先出，栈是先入后出。可以说两者的追加操作都是一样的，唯一不同的是取出元素的操作。

如果要按照队列的逻辑取出栈中的元素，那么就需要把栈进行逆序，既然如此，思路就明确了。先创建一个栈 `s1`，添加元素时就把元素放到 `s1`；在创建一个栈 `s2`，当要取出元素时，就把 `s1` 中的元素全部弹出放到 `s2` 中，在弹出 `s2` 的末尾元素即可。那么有两个小细节：

1. 如果 `s2` 中已经有元素了，那么不需要操作 `s1`，可以节省时间
2. 如果 `s1` 和 `s2` 都没有元素，返回 -1。

```cpp
class CQueue {
public:
  stack<int> s1;
  stack<int> s2;
  CQueue() {
  }
  
  void appendTail(int value) {
    s1.push(value);
  }
  
  int deleteHead() {
    if (s2.size()) {
      auto a = s2.top();
      s2.pop();
      return a;
    }
    else if (s1.size()){
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      auto a = s2.top();
      s2.pop();
      return a;
    }
    return -1;
  }
};
```

## 剑指 Offer 30. 包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

这个题好像也很经典，我想的是借助 `map` 来实现这一结构，毕竟 `map` 是 `key` 有序的，且能记录每个元素出现的次数，当最小值全部弹出时，可以顺滑的切换到下一个最小值，那么更新最小值的方法就是返回 `map` 的第一个 `key`。

对于最小栈而语言，`min` 方法就返回最小值，`top` 方法就返回栈顶元素，这个没啥好说的，重点是 `push` 方法和 `pop` 方法。

1. 对于 `push` 方法而言，压入元素时，可以更新最小值，并记录这个元素出现的次数。但是需要注意的是，当栈为空的时候，需要更新最小值为 `INT_MAX`。比如一个栈初始元素是 `1,2,3`，最小值是 1；栈全部弹空时，压入元素 `4`，此时最小值是 4。
2. 对于 `pop` 而言，先判断栈顶元素是不是最后一次出现，如果是，删除在 `map` 中的 `key`，避免这个元素已经没了，但最小值还是这个元素；而后判断弹出元素是不是最小值，如果是，则返回 `map` 第一个 `key` 即可。

```cpp
class MinStack {
public:
  /** initialize your data structure here. */
  int minn{INT_MAX};
  map<int, int> m1;
  stack<int> s1;
  MinStack() {

  }
  
  void push(int x) {
    if (s1.empty())
      minn = INT_MAX;
    s1.push(x);
    if (x < minn)
      minn = x;
    m1[x] ++;
  }
  
  void pop() {
    auto a = s1.top();
    m1[a]--;
    if (m1[a] <= 0) {
      m1.erase(a);
    }
    if (a == minn) {
      minn = m1.begin()->first;
    }
    s1.pop();
  }
  
  int top() {
    return s1.top();
  }
  
  int min() {
    return minn;
  }
};
```