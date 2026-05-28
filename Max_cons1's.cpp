//This code simply checks the array one by one and counts how many 1s come continuously.
//If a 0 is found, the count starts again from 0.


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
                maxi = max(maxi,cnt);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;
    }
};