class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char lastOp = '+';
        long currentNum = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                currentNum = currentNum * 10 + (s[i] - '0');
            }
            
            if ((!isdigit(s[i]) && !isspace(s[i])) || i == n - 1) {
                if (lastOp == '+') {
                    st.push(currentNum);
                } else if (lastOp == '-') {
                    st.push(-currentNum);
                } else if (lastOp == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * currentNum);
                } else if (lastOp == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / currentNum);
                }
                
                lastOp = s[i];
                currentNum = 0;
            }
        }
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};