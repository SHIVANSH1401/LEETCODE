/*This solution uses Kadane’s Algorithm, which keeps track of the current subarray sum while traversing the array. If the current sum becomes negative, it is reset to 0 since carrying a negative sum forward would only reduce the maximum sum of future subarrays    */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            maxi = max(maxi, sum);

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};