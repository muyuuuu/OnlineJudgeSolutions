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