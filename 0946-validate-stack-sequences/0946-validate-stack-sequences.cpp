class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        if(n != m) return false;
        
        stack<int> st;
        int i = 0; 
        int j = 0;

        while(i < n){
            st.push(pushed[i]);
            i++;
            while(!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};