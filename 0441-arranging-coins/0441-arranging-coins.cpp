class Solution {
public:
    int arrangeCoins(int n) {
        int rows = 1 ;
        int count  = 0;

        long long coinRe = n;

        while(coinRe >= rows ){
            coinRe -= rows;
            count++;
            rows++;

        }
        return count;
    }
};