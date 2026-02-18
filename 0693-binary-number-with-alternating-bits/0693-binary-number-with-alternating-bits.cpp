class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = std::format("{:b}", n);
        int w = s.length();

        for(int i =0 ; i< w ; i++){
            if(s[i]==s[i+1]) return false;
        }
        return true;
    }
};