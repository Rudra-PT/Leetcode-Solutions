class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            int num = asteroids[i];
            bool destroyed = false;
            while (!st.empty() && st.top() > 0 && num < 0) {
                if (abs(st.top()) < abs(num)) {
                    st.pop(); 
                    continue; 
                } else if (abs(st.top()) == abs(num)) {
                    st.pop();
                    destroyed = true;
                } else {
                    destroyed = true; 
                }
                break; 
            }

            if (!destroyed) {
                st.push(num);
            }
        }
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};