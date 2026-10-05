class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int> st; 
        int count = 0;

        for(int i = 0; i < n; i++){
            char temp = s[i];

            if(temp == '('){
                st.push(count);
                count = 0; 
            }
            else if (temp == ')'){
                count = st.top() + max(2 * count, 1);
                st.pop();
            }
        }
        
        return count;
    }
};