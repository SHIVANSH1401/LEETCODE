 /*This solution uses the Prefix Sum + Hash Map technique. As we traverse the array, we store the frequency of each prefix sum. 
 If (currentPrefixSum - k) has appeared before, then a subarray with sum k exists, and we add its frequency to the answer.*/


 
 class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int preSum = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];

            int remove = preSum - k;

            cnt += mpp[remove];

            mpp[preSum]++;
        }

        return cnt;
    }
};