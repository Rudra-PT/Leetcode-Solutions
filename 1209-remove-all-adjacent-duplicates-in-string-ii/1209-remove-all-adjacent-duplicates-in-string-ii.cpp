class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char , int>>st;

        for(int i =0 ; i< n ; i++){
            char temp = s[i];
            if(st.empty() || st.top().first != temp){
                st.push({temp,1});
            }
            else{
                st.top().second++;
            }
            if(st.top().second == k){
                st.pop();
            }
        }
        string ans ="";
            while(! st.empty()){
                auto curr = st.top();
                st.pop();
                ans.append(curr.second , curr.first);
            }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};