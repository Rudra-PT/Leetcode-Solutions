class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLen =INT_MIN ;
        int n  = s.length();
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j<n ; j++){
                if(s[i]==s[j]){
                    maxLen = max(maxLen , j-i-1);
                }
            }
        } 
        if(maxLen == INT_MIN){
            return -1;
        }
        else{
            return maxLen;
        }

    }
};