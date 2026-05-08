class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long totalWait = 0;
        long long chefFree = 0;
        for(int i = 0 ; i< n ; i++){
            long long arrival = customers[i][0];
            long long prepTime = customers[i][1];

            long long startTime = max(arrival , chefFree);
            long long finishTime = startTime + prepTime;

            totalWait+= (finishTime - arrival);
            chefFree= finishTime;
        }
        return (double) totalWait/n;
    }
};