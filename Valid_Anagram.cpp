/*First, we check whether both strings have the same length. 
Then we count each character in the first string and decrease its count using the second string. 
If any count becomes negative, the strings do not contain the same characters, so they are not anagrams.*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> freq(26,0);

         for (char ch : s)
            freq[ch - 'a']++;

        for (char ch : t) {
            freq[ch - 'a']--;

            if (freq[ch - 'a'] < 0)
                return false;
        }
        return true;
    }
};