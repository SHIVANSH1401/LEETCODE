/*We use a deque to store useful elements in decreasing order, so the front always contains the maximum of the current window.
When the window moves, remove elements that are out of range and smaller elements that can never become maximum.
This gives an O(n) solution because every element enters and leaves the deque at most once.*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};