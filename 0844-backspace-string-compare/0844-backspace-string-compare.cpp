class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (i > 0) {
                    s.erase(i - 1, 2); 
                    i -= 2;  
                } else {
                    s.erase(i, 1);   
                    i--;       
                }
            }
        }
        for (int j = 0; j < t.size(); j++) {
            if (t[j] == '#') {      
                if (j > 0) {
                    t.erase(j - 1, 2); 
                    j -= 2;
                } else {
                    t.erase(j, 1);  
                    j--;
                }
            }
        }

        return s == t;
    }
};