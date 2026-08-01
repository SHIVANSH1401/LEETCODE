/*Binary exponentiation computes the power by using the binary representation of the exponent.
 If the current bit is 1, multiply the answer by the current base; then square the base and right-shift the exponent. 
 This reduces the complexity from O(n) to O(log n).*/class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        while (N > 0) {
            if (N & 1)
                ans *= x;

            x *= x;
            N >>= 1;
        }

        return ans;
    }
};