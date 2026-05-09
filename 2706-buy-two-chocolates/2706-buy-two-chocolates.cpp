class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin() , prices.end());
        int leftover = 0 ;

        if(prices[0]+prices[1] <= money){
            leftover  = money - (prices[0]+prices[1]);
            return leftover;
        }
        return money;
    }
};