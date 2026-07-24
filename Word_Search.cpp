/*We try to start the word from every cell in the board. If the current character matches, we recursively search in the four directions (up, down, left, right) while marking the current cell as visited. After exploring all possibilities, we restore the cell (backtracking) so it can be used in other paths.*/

class Solution {
public:
    bool solve(int i, int j, int ind, vector<vector<char>>& board, string& word) {

        if (ind == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[ind])
            return false;

        char ch = board[i][j];
        board[i][j] = '#';

        bool found = solve(i + 1, j, ind + 1, board, word) ||
                     solve(i - 1, j, ind + 1, board, word) ||
                     solve(i, j + 1, ind + 1, board, word) ||
                     solve(i, j - 1, ind + 1, board, word);

        board[i][j] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }
};