class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int row = 1; row <= numRows; row++) {
            vector<int> ansRow;
            long long val = 1;

            for (int col = 1; col <= row; col++) {
                ansRow.push_back(val);
                val = val * (row - col) / col;
            }

            ans.push_back(ansRow);
        }

        return ans;
    }
};