/*We build the parentheses string one character at a time. We can always add '(' if any are left, but we can add ')' only when there are more closing brackets remaining than opening ones, ensuring the sequence stays valid. When both counts become zero, we store the completed string.*/


class Solution {
public:
    void solve(int open, int close, string curr, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }

        if (open > 0)
            solve(open - 1, close, curr + '(', ans);

        if (close > open)
            solve(open, close - 1, curr + ')', ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, n, "", ans);
        return ans;
    }
};