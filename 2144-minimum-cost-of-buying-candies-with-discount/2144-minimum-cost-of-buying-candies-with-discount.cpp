class Solution {
public:
    
    int minimumCost(vector<int>& cost) {
    int count = 0;
    sort(cost.begin(), cost.end());
    int buy = cost.size() - 1;
    while (buy >= 0) {
        count += cost[buy];
        if (buy > 0) {
            count += cost[buy - 1];
        }
        buy -= 3;
    }
    
    return count;
}
};