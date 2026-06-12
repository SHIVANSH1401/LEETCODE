/*This solution uses Binary Search to locate a peak element without scanning the entire array.
 By checking whether the current position lies on an increasing or decreasing slope, 
 we can safely move toward a side that must contain a peak.*/



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] &&
                nums[mid] > nums[mid + 1])
                return mid;

            if (nums[mid] > nums[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};