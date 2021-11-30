- [哈希](#哈希)
  - [剑指 Offer 03. 数组中重复的数字](#剑指-offer-03-数组中重复的数字)

# 哈希

## 剑指 Offer 03. 数组中重复的数字

简单的哈希表映射即可。

```cpp
class Solution {
public:
  int findRepeatNumber(vector<int>& nums) {
    unordered_map<int, int> m1;
    int res;
    for (auto i : nums) {
      if (m1.count(i)) {
        res = i;
        break;
      }
      m1[i] = 8;
    }
    return res;
  }
};
```