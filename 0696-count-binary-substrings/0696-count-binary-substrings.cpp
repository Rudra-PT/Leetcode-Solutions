class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevRunLength = 0;
        int currRunLength = 1;
        int totalSubstrings = 0;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                currRunLength++;
            } 
            else {
                totalSubstrings += min(prevRunLength, currRunLength);
                prevRunLength = currRunLength;
                currRunLength = 1;
            }
        }
        totalSubstrings += min(prevRunLength, currRunLength);
        
        return totalSubstrings;
    }
};