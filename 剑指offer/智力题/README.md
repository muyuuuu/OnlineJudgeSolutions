- [智力题](#智力题)
  - [剑指 Offer 45. 把数组排成最小的数](#剑指-offer-45-把数组排成最小的数)

# 智力题

指不需要使用任何数据结构，但思路比较清奇的题目。

## 剑指 Offer 45. 把数组排成最小的数

输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。如 `[3,30,34,5,9]` 的结果是 `"3033459"`。

我当时还在想，这要是暴力枚举得累死，但是呢，仿佛也有规律可循，也就是每次都选择最小的数字放在前面，可是 `3` 比 `30` 而言，`30` 该出现在前面，当时还想，这咋排序。直到看了答案，我们只需要比较字符串下的 `330` 和 `303` 谁更小就可以了，思路清奇。

```cpp
class Solution {
public:
  string minNumber(vector<int>& nums) {
    vector<string> tmp;
    for (auto i : nums)
      tmp.push_back(to_string(i));
    sort(tmp.begin(), tmp.end(), [&tmp](string x, string y) {
      return x + y < y + x;
    });
    string res{""};
    for (auto i : tmp)
      res += i;
    return res;
  }
};
```