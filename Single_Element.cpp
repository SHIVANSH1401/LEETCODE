/*This solution uses Binary Search on the sorted array. Before the single element, pairs start at even indices, while after it, this pattern breaks. By checking whether nums[mid] equals nums[mid+1], we can eliminate half of the search space each time, achieving O(log n) time complexity.*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1])
                low = mid + 2;
            else
                high = mid;
        }

        return nums[low];
    }
};