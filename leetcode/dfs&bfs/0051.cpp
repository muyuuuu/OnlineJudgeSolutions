class Solution {
private:
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return res;
    }

    bool valid(vector<string>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = col + 1, j = row - 1; i < board.size() && j >= 0; i++, j--) {
            if (board[j][i] == 'Q')
                return false;
        }

        return true;
    }

    void dfs(vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board[row].size(); col++) {
            if (!valid(board, row, col)) {
                continue;
            }
            else {
                board[row][col] = 'Q';
                dfs(board, row + 1);
                board[row][col] = '.';
            }
        }
        
    }
};

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 58.47% 的用户
// 内存消耗： 7.2 MB , 在所有 C++ 提交中击败了 67.70% 的用户
