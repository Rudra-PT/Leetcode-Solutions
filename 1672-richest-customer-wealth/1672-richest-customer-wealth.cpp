class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int maxWel = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int CurrentSum = 0;
        for(int j = 0 ; j< accounts[i].size(); j++){
            CurrentSum += accounts[i][j];
        }
        maxWel = max(maxWel , CurrentSum);
        }
        return maxWel;
    }
};