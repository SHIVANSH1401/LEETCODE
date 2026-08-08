/*Since the array is circular, we can imagine writing the array twice. This lets us check elements that come after the last position.

We use a stack to keep possible greater elements. While the current element is bigger than the stack's top, we remove the smaller elements. The element left at the top is the next greater element. We traverse 2n times and use i % n to move back to the beginning of the array.*/  
  
  
  class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int x = nums[i % n];

            while (!st.empty() && st.top() <= x)
                st.pop();

            if (i < n && !st.empty())
                ans[i] = st.top();

            st.push(x);
        }

        return ans;
    }
};