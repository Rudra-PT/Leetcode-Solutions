class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(char x : s){
                if(x == '*'){
                    if(len)
                        len--;
                }
                else if(x == '#'){
                    len*=2;
                }
                else if(x == '%'){
                   continue;
                }
                else {
                   len++;
                }
        }
        if(k>=len) return '.';

        for(int i= s.size()-1;i>=0;i--){
            if(s[i] == '*'){
                len++;
            }
            else if(s[i]=='#'){
                len = len/2;
                if(k>=len){
                    k -= len;
                }
            }
            else if(s[i] == '%'){
                k = len - k -1; 
            }
            else{
                len--;            
            }
            if(k== len){
                return s[i];
            }
        }
        return '.';
    }
};