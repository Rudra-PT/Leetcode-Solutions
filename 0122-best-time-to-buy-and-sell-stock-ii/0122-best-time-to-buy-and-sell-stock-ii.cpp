class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0; 
        
        int totalProfit = 0;
        int i = 0;
        while (i < n - 1) {
            while (i < n - 1 && prices[i] >= prices[i+1]) {
                i++;
            }
            int buyPrice = prices[i];
            while (i < n - 1 && prices[i] <= prices[i+1]) {
                i++;
            }
            int sellPrice = prices[i];
            totalProfit += sellPrice - buyPrice;
        }
        
        return totalProfit;
    }
};