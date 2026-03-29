class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(s1 ==s2 ) return true;
        for(int i = 0 ; i< n ; i++){
            if(s1[0]!= s2[0]){
                swap(s2[0] , s2[2]);
            }
             if(s1[1]!= s2[1]){
                swap(s2[1] , s2[3]);
            }
            if(s2==s1) return true;
        }
        return false;
    }
};