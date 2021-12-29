- [智力题](#智力题)
  - [剑指 Offer 45. 把数组排成最小的数](#剑指-offer-45-把数组排成最小的数)
  - [剑指 Offer 66. 构建乘积数组](#剑指-offer-66-构建乘积数组)
  - [剑指 Offer 14- I. 剪绳子](#剑指-offer-14--i-剪绳子)
  - [剑指 Offer 14- II. 剪绳子 II](#剑指-offer-14--ii-剪绳子-ii)

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

## 剑指 Offer 14- I. 剪绳子

我当时以为是复杂的动态规划，后来发现题解中进行了数学推导，划分为 3 段时解最大，因此......直接背答案吧。

```cpp
class Solution {
public:
  int cuttingRope(int n) {
    if (n <= 3)
      return n - 1;
    int x, y;
    x = n / 3;
    y = n % 3;
    if (y == 0)
      return int(pow(3, x));
    else if (y == 1)
      return int(pow(3, x - 1) * 4);
    return int(pow(3, x) * 2);
  }
};
```

## 剑指 Offer 14- II. 剪绳子 II

需要增加越界处理，如 `pow(3, 40)` 会溢出，所以在乘法期间进行模运算即可。

```cpp
class Solution {
public:

  const int mod = 1000000007;
  int calc(int x) {
    long long int tmp = 1;
    for (int i = 0; i < x; i ++) {
      tmp *= 3;
      if (tmp > mod)
        tmp %= mod;
    }
    return tmp;
  }

  int cuttingRope(int n) {
    if (n <= 3)
      return n - 1;
    int x = n / 3, y = n % 3;
    int a;
    long long int res;
    if (y == 0) {
      res = calc(x);
      a = 1;
    }
    else if (y == 1) {
      a = 4;
      res = calc(x - 1);
    }
    else {
      a = 2;
      res = calc(x);
    }
    return res * a % mod;
  }
};
```

## 剑指 Offer 51. 数组中的逆序对

 重新学习了一下归并排序，思路挺不错。在归并的时候，统计逆序数的数量。此外注意下标，均要能取到后一位。

```cpp
class Solution {
public:
  vector<int> v;
  vector<int> tmp;
  int reversePairs(vector<int>& nums) {
    int n = nums.size();
    this->v = nums;
    tmp.resize(n);
    int res = merge(0, n - 1);
    return res;
  }

  int merge(int l, int r) {
    if (l >= r)
      return 0;
    int m = l + (r - l) / 2;
    int res = merge(l, m) + merge(m + 1, r);

    int a = l, b = m + 1;

    for (int i = l; i <= r; i++)
      tmp[i] = v[i];

    for (int i = l; i <= r; i++) {
      // 左侧走到头，一定来自右侧
      if (a == m + 1)
        v[i] = tmp[b++];
      // 右侧走到头或者左侧小，一定来自左侧
      else if (b == r + 1 || tmp[a] <= tmp[b])
        v[i] = tmp[a++];
      // 右侧比左侧小，统计逆序数，各个子数组已经排序好
      else {
        v[i] = tmp[b++];
        res += m - a + 1;
      }
    }

    return res;
  }
};
```
