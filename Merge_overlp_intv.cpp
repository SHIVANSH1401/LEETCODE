/*This solution uses the Sorting + Greedy approach. 
After sorting the intervals by their starting time, each interval is compared with the last merged interval. 
If they overlap, they are merged by extending the end point; otherwise, the interval is added as a new entry.*/




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};