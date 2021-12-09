- [动态规划](#动态规划)
  - [剑指 Offer 42. 连续子数组的最大和](#剑指-offer-42-连续子数组的最大和)
  - [剑指 Offer 10- II. 青蛙跳台阶问题](#剑指-offer-10--ii-青蛙跳台阶问题)
  - [剑指 Offer 10- I. 斐波那契数列](#剑指-offer-10--i-斐波那契数列)
  - [剑指 Offer 46. 把数字翻译成字符串](#剑指-offer-46-把数字翻译成字符串)
  - [剑指 Offer 47. 礼物的最大价值](#剑指-offer-47-礼物的最大价值)

# 动态规划

## 剑指 Offer 42. 连续子数组的最大和

经典的动态规划问题，设置 dp[i] 表示为数组前 i 个元素的最大和，base case 为数组的第一个元素为 dp[0]，转移方程为：当前元素要么单独一组，要么和之前的状态一组，选最大值即可。

```cpp
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int res{INT_MIN}, n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i] = max(nums[i], dp[i-1] + nums[i]);
    }
    for (auto item : dp) {
      if (item > res)
        res = item;
    }
    return res;
  }
};
```

## 剑指 Offer 10- II. 青蛙跳台阶问题

这个也是动态规划中常见的问题，不过这次以分治来求解。青蛙跳到第 n 层的结果取决于青蛙跳到第 n-1 层的结果和青蛙跳到第 n-2 层结果的和，然后往回递推即可。当递推到第 0 层和第 1 层时，直接返回结果 1 即可。

此外还有注意事项，当结果很大需要 % 一个很大的数时，可以在中间就 % 一下，不然后期结果会很大导致溢出。

```cpp
class Solution {
public:
  unordered_map<int, int> m1;
  int numWays(int n) {
    m1[0] = 1;
    m1[1] = 1;
    int res = dp(n);
    return res % 1000000007;
  }
  int dp(int n) {
    if (m1.count(n))
      return m1[n];
    if (n == 1 || n == 0)
      return 1;
    m1[n] = (dp(n-1) + dp(n-2)) % 1000000007;
    return m1[n];
  }
};
```

## 剑指 Offer 10- I. 斐波那契数列

斐波那契数列是很经典的问题了，想必在学数组或递归的时候都是用这个东西举的例子，但是斐波那契数列也可以理解为 dp 数组的状态转移，因此就把这道题算做动态规划了。

```cpp
class Solution {
public:
  int fib(int n) {
    if (n < 2) {
      return n;
    }
    int a = 0, b = 1, t;
    for (int i = 0; i < n - 1; i++) {
      t = b;
      b = (a + b) % 1000000007;
      a = t % 1000000007;
    }
    return b;
  }
};
```

## 剑指 Offer 46. 把数字翻译成字符串

动态规划还是老样子，先列出状态与 base case，而后写出转移条件，最后调整细节。

1. 设置 dp[i] 表示长度为 i 的数字能翻译的结果数，那么 base case 为 dp[i] 的初始值为 1，即使最极端的情况也是有一种结果的
2. 之后是比较难思考的状态转移：
   1. 最不济的情况是 dp[i] = dp[i-1]，表示当前字符只能单独翻译；
   2. 或者说当前字符能和前面的字符组合使用，此时有两种情况，组合或者不组合，不组合为 dp[i-1]，组合为 dp[i-2]。考虑这两种情况，dp[i] = dp[i-2] + dp[i-1]。
3. 细节设置，需要完全遍历字符串，以及需要访问 i-2，确定出遍历范围和 dp 的大小。

```cpp
class Solution {
public:
  int translateNum(int num) {
    int res{0};
    string s = to_string(num);
    int n = s.size();

    vector<int> dp(n + 1, 1);

    if (n == 0)
      return 0;
    
    for (int i = 2; i <= n; i++) {
      if ((s[i - 2] == '2' && s[i - 1] <= '5') || (s[i - 2] == '1')) {
        dp[i] = dp[i-2] + dp[i-1];
      } else 
        dp[i] = dp[i - 1];
    }
    
    return dp[n];
  }
};
```

## 剑指 Offer 47. 礼物的最大价值

典型的二维动态规划，先对矩阵的行和列设置初值；而后其余部分的取值来源有两个方向，按照位置进行 dp 即可。

```cpp
class Solution {
public:
  int maxValue(vector<vector<int>>& grid) {
    int row = grid.size();
    if (row == 0)
      return 0;
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < col; i++) {
      dp[0][i] = (dp[0][i-1] + grid[0][i]);
    }
    for (int i = 1; i < row; i++) {
      dp[i][0] = (dp[i-1][0] + grid[i][0]);
    }
    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
      }
    }
    int maxn{-1};
    for (int i = 0; i < col; i++) {
      maxn = max(maxn, dp[row-1][i]);
    }
    return maxn;
  }
};
```