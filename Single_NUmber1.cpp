/*I traverse the array once and keep XORing each element with a variable ans. Since duplicate numbers cancel each other out (a ^ a = 0), only the number that appears once remains. This gives the answer in O(n) time and O(1) space.*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int num : nums)
            ans ^= num;

        return ans;
    }
};