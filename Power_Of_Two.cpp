/*A power of two can be repeatedly divided by 2 until it becomes 1.
 If at any point the number is non-positive or not divisible by 2, it cannot be a power of two.*/


class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n == 1)
            return true;

        if (n <= 0 || n % 2 != 0)
            return false;

        return isPowerOfTwo(n / 2);
    }
};
