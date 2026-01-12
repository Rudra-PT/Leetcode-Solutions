class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>unique;
        int n = s.length();
        int maxLen = 0 ;
        int left = 0 ; 
        for(int right = 0 ;  right< n ; right++){

            while(unique.find(s[right])!= unique.end()){
                unique.erase(s[left]);
                left++;
            }
            unique.insert(s[right]);
            maxLen = max(maxLen , right-left+1);
        }
        return maxLen;

        }


};