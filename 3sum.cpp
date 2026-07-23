/*
 * This solution uses the Sorting + Two Pointer technique.
 * After sorting the array, one element is fixed at a time,
 * and two pointers are used to efficiently find the other two numbers
 * that make the sum equal to zero while avoiding duplicate triplets.
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(1) excluding output
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        // Early termination: if smallest element is positive, no solution exists
        if (nums[0] > 0) return ans;
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate elements for the fixed number
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Early termination: if current element is positive, no more solutions
            if (nums[i] > 0) break;
            
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // Skip duplicates on left pointer
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    
                    // Skip duplicates on right pointer 
                    while (left < right && nums[right] == nums[right - 1]) right--;
                }
            }
        }
        return ans;
    }
};
