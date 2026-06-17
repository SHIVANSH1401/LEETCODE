/*This solution uses Binary Search on the answer. We guess the maximum sum allowed for each subarray and count how many subarrays are needed. 
If more than k subarrays are required, we increase the limit; otherwise, we try a smaller limit to get the minimum possible largest sum.*/


class Solution {
public:
    int countParts(vector<int>& nums, int maxSum) {
        int parts = 1, sum = 0;

        for (int num : nums) {
            if (sum + num <= maxSum)
                sum += num;
            else {
                parts++;
                sum = num;
            }
        }
        return parts;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;

            if (countParts(nums, mid) > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
