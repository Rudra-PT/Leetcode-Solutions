class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0; 
        int n = s.length();
        stack<char> st;
        
        for(int i = 0; i < n; i++) {
            char currentChar = s[i];
            
            if (currentChar == 'b') {
                st.push(currentChar);
            } 
            else if (!st.empty()) {
                count++;
                st.pop();
            }
        }
        return count;
    }
};