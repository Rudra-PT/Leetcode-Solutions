class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        int n = strs.size();
        string first = strs[0] , end = strs[n-1] , ans="";

        for(int i = 0 ; i < first.size() ; i++){
            if(first[i] == end[i]){
                ans+=first[i];
            }
            else break;
        }
        return ans;
    }
};