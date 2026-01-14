class Solution {
public:
    int maxPower(string s) {
        int n  = s.length();
        int maxLen = 0 ; 
        int i = 0;
        int j = i;
        
        for(i = 0 ; i< n; i++){
            while(s[i]==s[j] && j<n){
                j++;
           }
           int len = j-i;
           maxLen = max(len , maxLen);

           i = j-1;
        }
        return maxLen;
    }
};