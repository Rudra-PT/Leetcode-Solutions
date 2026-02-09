class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            char token = s[i];
            
            if (token == '(') {
                st.push(token);
            } else {

                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(token);
                }
            }
        }
        return st.size();
    }
};