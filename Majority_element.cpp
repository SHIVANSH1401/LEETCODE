/*This solution uses Moore's Voting Algorithm. Every time we see a different element, it cancels out one occurrence of the current candidate.
 Since the majority element appears more than half the time, it cannot be completely canceled and remains the final answer.*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;

        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            }
            else if (nums[i] == el) {
                cnt++;
            }
            else {
                cnt--;
            }
        }

        return el;
    }
};