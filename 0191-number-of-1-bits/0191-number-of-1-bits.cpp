class Solution {
public:
    int hammingWeight(int n) {
        string s = std :: format("{:b}" , n);
        int count = 0 ;
        int w = s.length();

        for(int i = 0 ; i < w ; i++){
            if(s[i] == '1') count++;
        }
        return count ;
    }
};