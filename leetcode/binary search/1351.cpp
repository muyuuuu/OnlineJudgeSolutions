class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int i{0}, j{col-1};
        int sum{0};
        while (i < row && j >= 0) {
            if (grid[i][j] < 0) {
                sum += (row - i);
                j -= 1;
            }
            else if (grid[i][j] == 0) {
                i += 1;
            }
            else if (grid[i][j] > 0) {
                i += 1;
            }
        }
        return sum;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了98.25%的用户
// 内存消耗：10.2 MB, 在所有 C++ 提交中击败了53.01%的用户