class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0;  
        int close_needed = 0;
        
        for(char c : s){
            if(c == '('){
                open_count++;
            }
            else if(c == ')'){
                if(open_count > 0){

                    open_count--;
                } else {
                    close_needed++;
                }
            }
        }
        
        // Total moves is the sum of unmatched open and close brackets
        return open_count + close_needed;
    }
};