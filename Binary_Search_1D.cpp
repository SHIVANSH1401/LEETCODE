/*This solution uses Binary Search on a sorted array. Instead of checking every element, 
it repeatedly divides the search space into two halves and eliminates the half where the target cannot exist. 
This reduces the search time significantly from O(N) to O(log N).*/


class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};