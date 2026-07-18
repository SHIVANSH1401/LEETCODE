/*Instead of multiplying x repeatedly, we divide the exponent by 2 in every recursive call. 
We compute the power of the smaller exponent once, square it, and multiply by x only when the exponent is odd.
 This reduces the number of operations significantly.*/


class Solution {
public:
    double power(double x, long long n) {
        if (n == 0)
            return 1;

        double half = power(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return half * half * x;
    }

    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }
};