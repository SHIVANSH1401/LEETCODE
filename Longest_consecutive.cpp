/*We store all elements in a hash set for fast lookup. Then, for each element, we check if its previous number is absent. 
If yes, that element is the start of a new consecutive sequence. We keep moving forward and count the sequence length, updating the maximum length found.*/



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        int longest = 1;
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};