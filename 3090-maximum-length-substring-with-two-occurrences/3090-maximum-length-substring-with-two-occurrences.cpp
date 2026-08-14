class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char ,int>res;
        int i = 0,j = 0 , n = s.length();
        int len = 0;

        while(j<n){
            res[s[j]]++;
            while(res[s[j]]>2){
                res[s[i]]--;
                i++;
            }
            len = max(len , j-i+1);
            j++;
        }
        return len;
    }
};