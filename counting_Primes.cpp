/*Then your segmented sieve code is correct, but it will not work on LeetCode 204 because that problem only passes a single integer n.

Tell me the problem number (e.g., LeetCode, GFG, CodeStudio) or share the problem link, and I'll provide the correct solution for that platform.*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i)
                    prime[j] = false;
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++)
            if (prime[i]) count++;

        return count;
    }
};