- [队列](#队列)
  - [剑指 Offer 40. 最小的k个数](#剑指-offer-40-最小的k个数)
  - [剑指 Offer 41. 数据流中的中位数](#剑指-offer-41-数据流中的中位数)

# 队列

## 剑指 Offer 40. 最小的k个数

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。首先，排序肯定是可以的，但是时间复杂度会很高。

考虑优先级队列，我们思考一下，因为要保留最小的 k 个数，设置一个优先级队列，从其中取出 k 个元素既可以满足题意。因此每次从优先级队列中取出的元素应该是最小的，所以应该设置小顶堆。

在简化一下，优先级队列的元素应该是 `arr.size()-k`，当优先级队列的元素大于这个数时，应该取出优先级队列中的最小元素存储到结果中。这样，就大大简化了优先级队列的开销。

```cpp
class Solution {
public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> queue;
    int n = arr.size() - k;
    vector<int> res;
    for (const auto& i : arr) {
      queue.push(i);
      if (queue.size() > n) {
        auto a = queue.top();
        res.push_back(a);
        queue.pop();
      }
    }
    return res;
  }
};
```

## 剑指 Offer 41. 数据流中的中位数

这个题属于那种不看答案完全想不出来的那种。由于数据流会频繁的增删数据，因此排序不可取。这里直接说思路了，设置两个优先级队列，一个是小顶堆，一个是大顶堆。数据流添加元素时，都需要移动两个队列的元素来保证「小顶堆是数组的后半部分，大顶堆是数组的前半部分」：

- 如果两个堆的数量相等，那么添加到小顶堆中，并把小顶堆最小的元素添加到大顶堆中；
- 否则添加到大顶堆，再把大顶堆最大的元素放入小顶堆；
- 求中位数时，直接取出两个队列的首元素进行操作即可。

```cpp
class MedianFinder {
public:
  priority_queue<int, vector<int>, greater<int>> minq;
  priority_queue<int> maxq;
  /** initialize your data structure here. */
  MedianFinder() {

  }
  
  void addNum(int num) {
    if (minq.size() == maxq.size()) {
      minq.push(num);
      auto a = minq.top();
      maxq.push(a);
      minq.pop();
    }
    else {
      maxq.push(num);
      auto a = maxq.top();
      minq.push(a);
      maxq.pop();
    }
  }
  
  double findMedian() {
    if (minq.size() == maxq.size())
      return (minq.top() + maxq.top()) / 2.0;
    else
      return 1.0 * maxq.top();
  }
};
```