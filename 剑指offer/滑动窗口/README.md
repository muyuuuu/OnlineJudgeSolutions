- [滑动窗口](#滑动窗口)
  - [剑指 Offer 59 - I. 滑动窗口的最大值](#剑指-offer-59---i-滑动窗口的最大值)

# 滑动窗口

## 剑指 Offer 59 - I. 滑动窗口的最大值

这个是迄今为止遇到的最有意思的题目。因为每次要取出滑动窗口内的最大值，而遍历求最大值是不现实的。因此需要实现特殊的队列，存储一个窗口内的最大值。

- 向队列中压入元素时，把比当前元素小的元素都删除。这样，队列中的元素就是降序排列的，每次取最大值，返回队首即可。
- 当弹出元素时，如果弹出的数值不是最大值，那么当前窗口的最大值仍然是队首元素，不用额外操作；如果滑出的元素是最大值，那么说明当前窗口内的最大值需要发生变化，因此弹出队首的最大值。

```cpp
class myque{
public:
  deque<int> q;
  int get_max() {
    return q.front();
  }
  void push(int val) {
    while (q.size() && val > q.back()) {
      q.pop_back();
    }
    q.push_back(val);
  }
  void pop(int val) {
    if (val == q.front())
      q.pop_front();
  }
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    myque q;
    for (int i = 0; i < nums.size(); i++) {
      if (i < k - 1)
        q.push(nums[i]);
      else {
        q.push(nums[i]);
        res.push_back(q.get_max());
        q.pop(nums[i - k + 1]);
      }
    }
    return res;
  }
};
```