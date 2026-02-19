#include <string>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) {
                
                int left = i;
                int right = i + 1;
        
                char leftChar = s[left];
                char rightChar = s[right];
                while (left >= 0 && right < n && s[left] == leftChar && s[right] == rightChar) {
                    count++;  
                    left--;    
                    right++;  
                }
            }
        }
        return count;
    }
};