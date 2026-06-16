/*We use binary search on the divisor value from 1 to the maximum element in the array. For each divisor, we calculate the sum of ceil(nums[i] / divisor). 
If the sum is within the threshold, we try a smaller divisor; otherwise, we increase the divisor. This helps find the smallest valid divisor efficiently*/


class Solution {
public:
    int sumByD(vector<int>& nums, int div) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)nums[i] / (double)div);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = (low + high) / 2;

            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};