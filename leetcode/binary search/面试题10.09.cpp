class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() <= 0)
            return false;
        int i{0}, j = matrix[0].size() - 1, row = matrix.size();
        while (i < row && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j -= 1;
            else
                i += 1;
        }
        return false;
    }
};

// 执行用时：116 ms, 在所有 C++ 提交中击败了69.85%的用户
// 内存消耗：10.5 MB, 在所有 C++ 提交中击败了40.95%的用户