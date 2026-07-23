/*We try every number from 1 to 9 exactly once. If we choose a number, 
we move to the next number so it cannot be reused. 
Whenever we have selected exactly k numbers and their sum becomes n, we store that combination.
*/



class Solution {
public:
    void solve(int num, int k, int target, vector<int>& ds,
               vector<vector<int>>& ans) {

        if (k == 0 && target == 0) {
            ans.push_back(ds);
            return;
        }

        if (k == 0 || target < 0)
            return;

        for (int i = num; i <= 9; i++) {
            ds.push_back(i);

            solve(i + 1, k - 1, target - i, ds, ans);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(1, k, n, ds, ans);

        return ans;
    }
};