/*A set with n elements has 2ⁿ possible subsets. We use the binary representation of numbers from 0 to (2ⁿ - 1) as masks, where each bit tells us whether to include (1) or exclude (0) an element from the subset.*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        for (int mask = 0; mask < (1 << n); mask++) {

            vector<int> subset;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i))
                    subset.push_back(nums[i]);
            }

            ans.push_back(subset);
        }

        return ans;
    }
};
