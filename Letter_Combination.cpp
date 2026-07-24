/*Each digit corresponds to a set of letters (like 2 → abc, 3 → def). We recursively pick one letter from the current digit and move to the next digit. When all digits are processed, the formed string is one valid combination.*/
git 


class Solution {
public:
    vector<string> ans;

    void solve(int ind, string digits, string curr, vector<string>& mp) {
        if (ind == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[ind] - '0'];

        for (char ch : letters) {
            solve(ind + 1, digits, curr + ch, mp);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(0, digits, "", mp);

        return ans;
    }
};