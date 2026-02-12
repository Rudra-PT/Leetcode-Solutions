class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        unordered_map<char,int> mpp;
        int maxLen = 0 ;

        for(int i = 0 ; i< n ; i++){
            mpp = {};
            for(int j = i ; j<n ; j++){
                mpp[s[j]]++;

                bool flag = true;
                int cnt = mpp[s[j]];

                for(auto it : mpp){
                    if(it.second !=cnt){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    maxLen= max(maxLen , j-i+1);
                }
            }
        }
        return maxLen;
    }
};