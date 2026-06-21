/*We traverse the string from right to left and look for the first odd digit. Once found, everything from the beginning up to that digit forms the largest possible odd number. If no odd digit exists, we return an empty string.*/

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};