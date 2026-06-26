/* 
We keep track of the current nesting depth using a counter. 
The first '(' and the last ')' of every primitive parentheses string are skipped, 
while all inner parentheses are added to the answer. 
This removes the outermost parentheses from each primitive.
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;

        // Range-based for loop
        // Same as:
        // for (int i = 0; i < s.size(); i++) {
        //     char ch = s[i];
        // }

        for (char ch : s) {
            if (ch == '(') {
                if (cnt > 0)
                    ans += ch;
                cnt++;
            } else {
                cnt--;
                if (cnt > 0)
                    ans += ch;
            }
        }

        return ans;
    }
};