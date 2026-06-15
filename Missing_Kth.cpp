/*This solution uses Binary Search on the sorted array. For any index mid, the number of missing positive integers before arr[mid] is arr[mid] - (mid + 1). We find the first position where the missing count becomes at least k, and the answer is low + k.*/




class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low + k;
    }
};