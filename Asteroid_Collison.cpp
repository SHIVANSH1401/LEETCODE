/*Use a stack to keep the surviving asteroids. When a positive asteroid meets a negative one, compare their sizes—the smaller explodes, and equal sizes destroy both.

The while loop handles multiple consecutive collisions.*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {

            while (!st.empty() && st.back() > 0 && a < 0) {

                if (st.back() < -a) {
                    st.pop_back();
                }
                else if (st.back() == -a) {
                    st.pop_back();
                    a = 0;
                }
                else {
                    a = 0;
                }
            }

            if (a != 0)
                st.push_back(a);
        }

        return st;
    }
};