class Solution {
public:
    string largestEven(string s) {
        int n = s.length();
        string ans = s;
        int i = n-1;
        while( i >= 0 && ans[i]== '1'){
            ans.pop_back();
            i--;
            
        }
        
        return ans;

    }
};