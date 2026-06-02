/*This solution uses a greedy approach by keeping track of the lowest stock price seen so far. For each day,
 it calculates the profit that would be earned by selling on that day and updates the maximum profit if it is better.
  This allows us to find the best buy-sell pair in a single traversal of the array.*/



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};