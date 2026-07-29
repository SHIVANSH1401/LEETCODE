//*Instead of repeatedly subtracting the divisor, we subtract the largest possible multiple of the divisor using left shifts (<<). This is much faster because each shift doubles the divisor, reducing the number of operations from linear to logarithmic.*/

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long ans = 0;

        while (dvd >= dvs) {

            int cnt = 0;

            while (dvd >= (dvs << (cnt + 1)))
                cnt++;

            ans += (1LL << cnt);
            dvd -= (dvs << cnt);
        }

        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};