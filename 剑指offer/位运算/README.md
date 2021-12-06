- [位运算](#位运算)
  - [剑指 Offer 15. 二进制中1的个数](#剑指-offer-15-二进制中1的个数)
  - [剑指 Offer 16. 数值的整数次方](#剑指-offer-16-数值的整数次方)
  - [剑指 Offer 56 - I. 数组中数字出现的次数](#剑指-offer-56---i-数组中数字出现的次数)

# 位运算

## 剑指 Offer 15. 二进制中1的个数

一个二进制常识：`n&(n-1)` 可以去掉二进制最后一位的 1。这样，写一个循环，逐步把最后以为的 1 给去掉即可，记录去掉的次数，就是二进制数中 1 的个数。

```cpp
class Solution {
public:
  int hammingWeight(uint32_t n) {
    int res{0};
    while (n) {
      n = n&(n-1);
      res++;
    }
    return res;
  }
};
```

## 剑指 Offer 16. 数值的整数次方

快速求 $x^n$，由于 $n$ 可以表示为二进制的 $b_m\cdots b_2b_1$，二进制展开为十进制：$n=1b_1+2b_2+\cdots+2^{m-1}b_m$，然后 $x^n=x^{1b_1}x^{2b_2}\cdots x^{2^{m-1}b_m}$。于是乎先算低位：

1. 取出幂数的最后一位，如果是 1，则乘以当前 $x$ 的次方，否则抛弃
2. 每次循环，$x$ 都要以次方的形式递增
3. 由于 int32 的取值范围是 −2147483648，2147483647，因此 −2147483648 转成正数会越界，因此需要将 n 存储为 long 类型的变量。

```cpp
class Solution {
public:
  double myPow(double x, int n) {
    bool flag{false};
    long long int n1;
    n1 = n;
    if (n < 0) {
      x = 1 / x;
      n1 = -n1;
    }
    double res{1.0};
    while (n1) {
      if (n1 & 1) {
        res *= x;
      }
      x *= x;
      n1 = n1 >> 1;
    }
    return res;
  }
};
```

## 剑指 Offer 56 - I. 数组中数字出现的次数

当时只知道可以使用异或运算一次性查找到数组中 1 个只出现 1 次的元素，但是不知道怎么找到 2 个只出现两次的 1 次的元素。

还是位运算，在异或完毕后，找到数字中二进制为 1 的地方，也就是只出现一次的数字不一样的地方，一个为 1，一个为 0。以此为依据，将数组划分为两组，一组是在那为 1 ，一组在那不为 1。开始进行异或，返回结果即可。

```cpp
class Solution {
public:
  vector<int> singleNumbers(vector<int>& nums) {
    int x{0}, y{0}, m{1}, n{0};
    for (auto i : nums)
      n ^= i;
    while ((n & m) == 0)
      m <<= 1;
    for (auto i : nums) {
      if ((i & m) == 0)
        x ^= i;
      else
        y ^= i;
    }
    return {x, y};
  }
};
```