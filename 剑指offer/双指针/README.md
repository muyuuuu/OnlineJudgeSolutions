- [双指针](#双指针)
  - [剑指 Offer 21. 调整数组顺序使奇数位于偶数前面](#剑指-offer-21-调整数组顺序使奇数位于偶数前面)
  - [剑指 Offer 22. 链表中倒数第k个节点](#剑指-offer-22-链表中倒数第k个节点)
  - [剑指 Offer 57. 和为s的两个数字](#剑指-offer-57-和为s的两个数字)
  - [剑指 Offer 57 - II. 和为s的连续正数序列](#剑指-offer-57---ii-和为s的连续正数序列)

# 双指针

## 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

刚开始我也没有想到使用双指针，直到看了题解。

1. 一个指针在开始，如果是奇数，向后移动；
2. 一个指针在末尾，如果是偶数，向前移动；
3. 否则不移动，并且在开始是偶数且末尾是奇数的情况下进行交换

```cpp
class Solution {
public:
  vector<int> exchange(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      if (nums[i] % 2 == 0 && nums[j] % 2 == 1) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        i++;
        j--;
        continue;
      }
      if (nums[i] % 2 == 1)
        i++;
      if (nums[j] % 2 == 0)
        j--;
    }
    return nums;
  }
};
```

## 剑指 Offer 22. 链表中倒数第k个节点

这个题第一次见是今年的 5 月份，没想到仍然记得题解。创建两个指针指向链表头：

1. 第一个指针向后移动 k 步
2. 两个指针同时向后移动，第一个指针为空时，返回第二个指针

```cpp
class Solution {
public:
  ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* p = head;
    ListNode* p1 = head;
    for (int i = 0; i < k; i++) {
      p = p->next;
    }
    while (p != nullptr) {
      p = p->next;
      p1 = p1->next;
    }
    return p1;
  }
};
```

## 剑指 Offer 57. 和为s的两个数字

既然数组是有序的，很容易往二分那边想，而二分用的也是双指针。对于这个题而言：

- 如果大于，右指针左移
- 如果小于，左指针右移
- 如果等于，返回结果

```cpp
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      if (nums[i] + nums[j] > target)
        j -= 1;
      else if (nums[i] + nums[j] < target)
        i += 1;
      else {
        return {nums[i], nums[j]};
      }
    }
    return {-1, -1};
  }
};
```

## 剑指 Offer 57 - II. 和为s的连续正数序列

其实实在不行可以暴力的。设置第一个指针 l，第二个指针 r = l + 1，之后移动右指针：
- 和小于 target，r 右移
- 等于 target，追加结果，l 右移
- 大于 target，l 右移

但是 l 右移需要讨论：
1. 如果是和等于 target 后，l 需要右移 x 个单位，x 个单位的和需要等于 r 右移一个单位的值
2. 如果和大于 target 后，l 右移一位，其实相当于模拟了

```cpp
class Solution {
public:
  vector<vector<int>> findContinuousSequence(int target) {
    int l = 0, sum = 0, sum1 = 0;
    vector<vector<int>> res;
    vector<int> tmp;
    int r;
    for (l = 1; l <= target / 2; ) {
      r = l + 1;
      sum = l + r;
      tmp.push_back(l);
      tmp.push_back(r);
      while (target > sum) {
        r ++;
        sum += r;
        tmp.push_back(r);
      }
      if (target == sum) {
        res.push_back(tmp);
        tmp.clear();
      }
      if (tmp.size() == 0) {
        r++;
        while (sum1 < r) {
          sum1 += l;
          l++;
        }
      }
      else
        l++;
      sum = 0;
      sum1 = 0;
      tmp.clear();
    }
    return res;
  }
};
```