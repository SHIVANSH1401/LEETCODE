/*We use Binary Search on the number of days. 
For each day, we count how many bouquets can be formed from flowers that have bloomed by then. 
If we can make at least m bouquets, we try a smaller day; otherwise, we need more days.*/


class Solution {
public:
    int bouquets(vector<int>& bloomDay, int day, int k) {
        int cnt = 0, bouquets = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        return bouquets + cnt / k;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = (low + high) / 2;

            if (bouquets(bloomDay, mid, k) >= m)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};