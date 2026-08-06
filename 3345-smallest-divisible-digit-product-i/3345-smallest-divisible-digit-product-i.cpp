class Solution {
public:
    int helper(int a){
        if (a == 0) return 0;
        
        int prod = 1;
        while(a > 0){
            int dig = a % 10;
            prod *= dig;
            a /= 10;
        }
        return prod;
    }
    
    int smallestNumber(int n, int t) {
        for(int i = n ;  ;i++){
            int res = helper(i);
            if(res % t == 0){
                return i;
            }
        }
        return 0;
    }
};