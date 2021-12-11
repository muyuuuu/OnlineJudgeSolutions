- [智力题](#智力题)
  - [剑指 Offer 45. 把数组排成最小的数](#剑指-offer-45-把数组排成最小的数)
  - [剑指 Offer 66. 构建乘积数组](#剑指-offer-66-构建乘积数组)

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

## 剑指 Offer 66. 构建乘积数组

题解上写的是上下三角，但我觉得把它理解成智力题会好一些。首先不能用除法，因为除法会出现 0 的情况，难以处理。

1. 正向乘法的时候，从 1 开始遍历，输入数组累积相乘放入 res，但放过最后一个，那么 res[i] 就是除去最后一个元素相乘的结果
2. 之后在反向乘法，从末尾往前遍历累计相乘，但放过 res 的当前元素，就是除去当前元素的相乘结果，可以理解为某种程度的哈希

其实我感觉我没说清楚，还是看代码吧。

```cpp
class Solution {
public:
  vector<int> constructArr(vector<int>& a) {
    int n = a.size();
    if (n == 0)
      return {};
    vector<int> res(n, 1);
    for (int i = 1; i < n; i++) {
      res[i] = res[i - 1] * a[i - 1];
    }
    int tmp{1};
    for (int i = n - 2; i >= 0; i--) {
      tmp *= a[i + 1];
      res[i] *= tmp;
    }
    return res;
  }
};
```