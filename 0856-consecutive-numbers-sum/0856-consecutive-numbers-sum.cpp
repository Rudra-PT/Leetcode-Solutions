class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for(int z=1;z*(z-1)/2<n;z++){
            if((n-z*(z-1)/2)%z==0){
                count++;
            }
        }
        return count;
    }
};