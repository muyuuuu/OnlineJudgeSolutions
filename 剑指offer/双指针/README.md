- [双指针](#双指针)
  - [剑指 Offer 21. 调整数组顺序使奇数位于偶数前面](#剑指-offer-21-调整数组顺序使奇数位于偶数前面)
  - [剑指 Offer 22. 链表中倒数第k个节点](#剑指-offer-22-链表中倒数第k个节点)

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