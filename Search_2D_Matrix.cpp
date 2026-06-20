/*We treat the 2D matrix as a single sorted 1D array and apply Binary Search. 
The row and column of any index are calculated using mid / m and mid % m. 
This lets us find the target efficiently without traversing the entire matrix.*/



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (matrix[mid / m][mid % m] == target)
                return true;
            else if (matrix[mid / m][mid % m] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};