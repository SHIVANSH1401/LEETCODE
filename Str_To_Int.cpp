/*We first ignore any leading spaces, then check for an optional + or - sign. Next, we convert the consecutive digits into a number while checking for overflow. If the value exceeds the integer range, we return INT_MAX or INT_MIN.*/
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        long long ans = 0;

        while (i < n && s[i] == ' ')
            i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            if (sign * ans >= INT_MAX)
                return INT_MAX;

            if (sign * ans <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};
