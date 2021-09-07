class Solution {
private:
    vector<vector<int>> memo;
public:
    int numTrees(int n) {
        memo.resize(n + 1);
        for (auto& i : memo) {
            i.resize(n + 1);
            fill(i.begin(), i.end(), 0);
        }
        return count(1, n);
    }

    int count(int l, int h) {
        if (l > h)
            return 1;
        
        if (memo[l][h] != 0)
            return memo[l][h];

        int res{0};

        for (int i = l; i <= h; i++) {
            int a = count(l, i-1);
            int b = count(i+1, h);
            res += a * b;
        }
        memo[l][h] = res;
        return res;
    }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 6.2 MB , 在所有 C++ 提交中击败了 5.00% 的用户
