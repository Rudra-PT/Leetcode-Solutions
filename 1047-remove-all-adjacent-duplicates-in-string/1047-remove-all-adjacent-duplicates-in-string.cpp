class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<char>st;
        string ans = "";

        for(int i = 0 ; i< n ; i++){
            char temp = s[i];
        
        if(st.empty() || st.top() != temp){
            st.push(temp);
        }
        else{
            st.pop();
        }
   }

        while(!st.empty()){
            char a = st.top();
            st.pop();
            ans+= a;
         }
         reverse(ans.begin() , ans.end());
         return ans;
    }
};