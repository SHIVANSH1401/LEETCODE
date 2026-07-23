/*This solution first sorts the array and fixes the first two numbers using nested loops. 
It then uses the two-pointer technique to find the remaining two numbers, 
efficiently generating all unique quadruplets whose sum equals the target while avoiding duplicates.
Time Complexity: O(n³), Space Complexity: O(1) excluding output*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());


        long long minSum = (long long)nums[0] + nums[1] + nums[2] + nums[3];
        if (minSum > target) return ans;

        long long maxSum = (long long)nums[n-1] + nums[n-2] + nums[n-3] + nums[n-4];
        if (maxSum < target) return ans;

        for (int i = 0; i < n - 3; i++) {
          
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            long long minSumWithI = (long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
            if (minSumWithI > target) break;

            
            long long maxSumWithI = (long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
            if (maxSumWithI < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
    
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                
                long long minSumWithIJ = (long long)nums[i] + nums[j] + nums[j+1] + nums[j+2];
                if (minSumWithIJ > target) break;
                
                long long maxSumWithIJ = (long long)nums[i] + nums[j] + nums[n-1] + nums[n-2];
                if (maxSumWithIJ < target) continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j]
                                  + nums[k] + nums[l];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        k++;
                        l--;

                     
                        while (k < l && nums[k] == nums[k - 1]) k++;
                       
                        while (k < l && nums[l] == nums[l - 1]) l--;
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};
