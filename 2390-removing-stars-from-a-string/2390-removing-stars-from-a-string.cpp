class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string ans;
        int n = s.length();
        for(int i = 0 ; i< n; i++){
            char error = '*';
        if(s[i]!= error){
            st.push(s[i]);
        }
        else{
            st.pop();
        }
        }
        while(!st.empty()){
             char c = st.top();
              ans+= c;
            st.pop();
        }
       reverse(ans.begin(), ans.end());
        return ans;
        
    }
};