class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }

    bool valid(vector<vector<char>>& board, char n, int r, int c) {
        for (int i = 0; i < 9; i++) {
            // 判断行是否存在重复
            if (board[r][i] == n) return false;
            // 判断列是否存在重复
            if (board[i][c] == n) return false;
            // 判断 3 x 3 方框是否存在重复
            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == n)
                return false;
        }
        return true;
    }

    bool dfs(vector<vector<char>>& board, int row, int col) {
        if (col == 9) {
            return dfs(board, row + 1, 0);
        }

        if (row == 9) {
            return true;
        }

        if (board[row][col] != '.') {
            return dfs(board, row, col + 1);
        }

        for (char ch = '1'; ch <= '9'; ch++) {
            if (!valid(board, ch, row, col)) {
                continue;
            }
            else {
                board[row][col] = ch;
                if(dfs(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }
};

// 执行用时： 20 ms , 在所有 C++ 提交中击败了 47.22% 的用户
// 内存消耗： 6.2 MB , 在所有 C++ 提交中击败了 78.07% 的用户
