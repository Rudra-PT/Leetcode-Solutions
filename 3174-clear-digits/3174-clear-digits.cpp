class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        int n = s.length();
        string ans ="";
        for(int i =0 ; i < n ; i++){
            char token = s[i];
            if( ! isdigit(token)){
                st.push(token);
            }
            else{
                st.pop();
            }
        }
          while(! st.empty()){
                ans+=st.top();
                st.pop();
            }
            reverse(ans.begin() , ans.end());
            return ans;
    }
};