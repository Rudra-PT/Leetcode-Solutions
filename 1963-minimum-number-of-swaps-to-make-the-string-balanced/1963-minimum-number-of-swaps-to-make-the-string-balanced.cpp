class Solution {
public:
    int minSwaps(string s) {
        int extraClose = 0; 
        int maxExtraClose = 0;
        for(int i =0 ;i < s.length() ; i++){
            if(s[i] == '[') extraClose--;
            else {
                extraClose++;  
           }
           maxExtraClose = max(maxExtraClose , extraClose);
        }
        
        return (maxExtraClose+1)/2;
    }
    
};