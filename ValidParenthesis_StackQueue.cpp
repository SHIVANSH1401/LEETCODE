/*Use a stack to keep track of opening brackets. For every closing bracket, verify that it matches the most recent opening bracket on the stack; otherwise, the string is invalid. If the stack is empty after processing the entire string, all brackets are properly matched.*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty()) return false;

                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};