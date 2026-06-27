/*We start from the end of the string and skip any extra spaces. Then we find each word and directly add it to the answer in reverse order, inserting a single space between words. This avoids storing all the words separately.*/
class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        string ans = "";

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int j = i;

            while (j >= 0 && s[j] != ' ')
                j--;

            if (!ans.empty())
                ans += " ";

            ans += s.substr(j + 1, i - j);

            i = j - 1;
        }

        return ans;
    }
};