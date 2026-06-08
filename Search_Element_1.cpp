/*This solution uses a modified Binary Search on a rotated sorted array. At each step, 
it identifies the sorted half and checks whether the target lies in that half,
 reducing the search space efficiently.*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[low] <= nums[mid]) { // Left half sorted

                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;

            } else { // Right half sorted

                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};