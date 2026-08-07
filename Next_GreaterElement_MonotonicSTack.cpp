/*A monotonic decreasing stack is used to find the next greater element for every value in nums2. While traversing from right to left, smaller elements are removed because they can never be the next greater element for future values. The results are stored in a hash map, allowing each element in nums1 to be answered in O(1) time.*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            if (st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        vector<int> ans;

        for (int x : nums1)
            ans.push_back(mp[x]);

        return ans;
    }
};