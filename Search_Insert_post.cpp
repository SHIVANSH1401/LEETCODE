/*This solution uses Binary Search on the sorted array. 
If the target is not found, low ends up at the exact position where the target should be inserted,
 giving the answer in O(log n) time and O(1) space.
 
 
 Why return low?
If target exists → return its index.
If target doesn't exist → low points to the correct insertion position after the loop ends.*/




class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};