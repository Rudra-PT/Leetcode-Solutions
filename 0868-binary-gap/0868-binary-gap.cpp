class Solution {
public:
    int binaryGap(int n) {
        string s = std::format("{:b}", n); 
        int i = 0; 
        int j = 1;
        int maxLen = 0;
        
        while(j < s.length()) {
            if(s[j] == '0') {

                j++;
            }
            else if(s[j] == '1') {
                maxLen = max(maxLen, j - i);
                i = j;
                j++;
            }
        }
        
        return maxLen;
    }
};