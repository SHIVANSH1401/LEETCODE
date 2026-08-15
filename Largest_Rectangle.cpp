/*We use a monotonic increasing stack to keep track of bars that can still form a rectangle.
When a smaller bar comes, we pop the taller bars and calculate their area using height × possible width.
This lets us find the largest rectangle in O(n) time.*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || heights[st.top()] > heights[i])) {

                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                ans = max(ans, h * width);
            }

            st.push(i);
        }

        return ans;
    }
};