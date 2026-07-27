/*We recursively split the string into numbers and insert +, -, or * between them. We keep track of the current calculated value and the previous operand so that multiplication follows the correct operator precedence. Whenever we reach the end of the string and the calculated value equals the target, we store the expression.*/

class Solution {
public:
    vector<string> ans;

    void solve(string num, int target, int ind,
               long long calc, long long prev, string expr) {

        if (ind == num.size()) {
            if (calc == target)
                ans.push_back(expr);
            return;
        }

        string curr = "";
        long long val = 0;

        for (int i = ind; i < num.size(); i++) {

            if (i > ind && num[ind] == '0')
                break;

            curr += num[i];
            val = val * 10 + (num[i] - '0');

            if (ind == 0) {
                solve(num, target, i + 1, val, val, curr);
            }
            else {
                solve(num, target, i + 1,
                      calc + val, val,
                      expr + "+" + curr);

                solve(num, target, i + 1,
                      calc - val, -val,
                      expr + "-" + curr);

                solve(num, target, i + 1,
                      calc - prev + prev * val,
                      prev * val,
                      expr + "*" + curr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        solve(num, target, 0, 0, 0, "");

        return ans;
    }
};