- [二分查找](#二分查找)
  - [剑指 Offer 04. 二维数组中的查找](#剑指-offer-04-二维数组中的查找)
  - [剑指 Offer 11. 旋转数组的最小数字](#剑指-offer-11-旋转数组的最小数字)
  - [剑指 Offer 53 - I. 在排序数组中查找数字 I](#剑指-offer-53---i-在排序数组中查找数字-i)

# 二分查找

## 剑指 Offer 04. 二维数组中的查找

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```

这个题把二分查找移动的指针视为数组的坐标即可，且要从一个有序的坐标开始，如左上角或者右下角。

- 如果等于目标，返回 `true`
- 如果大于目标，那么向左移动
- 如果小于目标，向下移动

注意坐标不要越界和极端情况的判断。

```cpp
class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if (n == 0)
      return false;
    int m = matrix[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
      if (matrix[i][j] == target)
        return true;
      else if (matrix[i][j] < target)
        i++;
      else
        j--;
    }
    return false;
  }
};
```

## 剑指 Offer 11. 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

与常规的二分搜索有所不同，对于常规的二分搜索有固定的模板，开区间搜索对应小于，闭区间搜索对应小于等于，这样搜索子区间时也能确定出什么时候 -1，什么时候不需要。

先来看代码：

```cpp
class Solution {
public:
  int minArray(vector<int>& numbers) {
    int l = 0, r = numbers.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (numbers[mid] < numbers[r]) {
        r = mid;
      }
      else if (numbers[mid] > numbers[r]) {
        l = mid + 1;
      }
      else {
        r--;
      }
    }
    return numbers[l];
  }
};
```

为什么 `r=mid` 而不是 `r=mid-1` 呢？明明是比区间搜索，`mid` 判断过一次不应该在判断了啊？这里需要注意的是：`numbers[mid]` 可能不是最小值，也可能是最小值。传统二分需要比较 `numbers[mid]` 和 `target` 的大小关系，但是这道题没有 `target`，也就是与众不同的地方。如果 `numbers[mid]` 是最小值，那么 `r=mid-1` 会直接错过最小值的搜索范围，看来二分搜索还需要灵活变化。

## 剑指 Offer 53 - I. 在排序数组中查找数字 I

基本的使用二分法查找左右边界，这次没有使用库函数偷懒，而是自己写的。在返回右侧编辑的时候需要注意，判断以及返回的都是 `l-1`
。

```cpp
class Solution {
public:

  int left_bound(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while(l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        r = mid - 1;
      }
      else if (nums[mid] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    if (l < 0 || l >= n)
      return -1;
    return nums[l] == target ? l : -1;
  }

  int right_bound(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while(l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        l = mid + 1;
      }
      else if (nums[mid] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    if (l-1 < 0 || l-1 >= n)
      return -1;
    return nums[l-1] == target ? l-1 : -1;
  }

  int search(vector<int>& nums, int target) {
    if (nums.size() == 0)
      return 0;
    auto a = left_bound(nums, target);
    if (a == -1)
      return 0;
    auto b = right_bound(nums, target);
    return b - a + 1;
  }
};
```