- [双指针](#双指针)
  - [剑指 Offer 21. 调整数组顺序使奇数位于偶数前面](#剑指-offer-21-调整数组顺序使奇数位于偶数前面)

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