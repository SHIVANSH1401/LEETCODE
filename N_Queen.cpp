/*We place one queen in each column. Before placing a queen, we check whether its row and both diagonals are free. If it is safe, we place the queen, recursively solve for the next column, and then remove it (backtracking) to explore other possible arrangements.*/

class Solution {
public:
    vector<vector<string>> ans;

    void solve(int col, vector<string>& board, vector<int>& row,
               vector<int>& upper, vector<int>& lower, int n) {

        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!row[i] && !lower[i + col] && !upper[n - 1 + col - i]) {

                board[i][col] = 'Q';
                row[i] = lower[i + col] = upper[n - 1 + col - i] = 1;

                solve(col + 1, board, row, upper, lower, n);

                board[i][col] = '.';
                row[i] = lower[i + col] = upper[n - 1 + col - i] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<int> row(n, 0), upper(2 * n - 1, 0), lower(2 * n - 1, 0);

        solve(0, board, row, upper, lower, n);

        return ans;
    }
};