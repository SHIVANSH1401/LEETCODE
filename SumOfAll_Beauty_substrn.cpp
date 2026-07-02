/*We consider every possible substring starting from each index. As we extend the substring, we update the frequency of characters and calculate the difference between the highest and lowest non-zero frequencies. Adding these differences for all substrings gives the total beauty sum.*/ 

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;

                int maxi = 0, mini = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                ans += maxi - mini;
            }
        }

        return ans;
    }
};