/*After sorting the strings, only the first and last strings need to be compared because they will be the most different.
 The common characters from the beginning of these two strings form the longest common prefix for the entire array.*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs.back();
        string ans = "";

        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) break;
            ans += first[i];
        }

        return ans;
    }
};