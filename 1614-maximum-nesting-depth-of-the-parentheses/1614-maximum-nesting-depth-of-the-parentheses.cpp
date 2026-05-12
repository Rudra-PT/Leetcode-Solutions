class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        stack<char> st;
        int maxLen = 0; 

        for (int i = 0; i < n; i++) {
            char temp = s[i];
            if (temp == '(') {
                st.push(temp);
                maxLen = max(maxLen, (int)st.size()); 
            }
            else if (temp == ')') {
                if (!st.empty()) {
                    st.pop();
                }
            }
        }  
        return maxLen;
    }
};