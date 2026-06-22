/*If we concatenate the string with itself (s + s), all possible rotations of s appear as substrings in the new string.
 So, we simply check whether goal exists inside s + s. If it does, the rotation is valid.*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string temp = s + s;

        return temp.find(goal) != string::npos;
    }
};