/*We use a counter to track the current nesting depth of parentheses. Every '(' increases the depth, and every ')' decreases it. The maximum value reached by the counter is the maximum nesting depth.*/

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                cnt++;
                ans = max(ans, cnt);
            }
            else if (ch == ')') {
                cnt--;
            }
     