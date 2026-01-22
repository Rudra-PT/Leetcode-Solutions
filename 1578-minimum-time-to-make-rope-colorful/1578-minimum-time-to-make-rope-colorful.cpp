class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int currentMax = 0;

        for (int i = 0; i < colors.size(); i++) {
            if (i > 0 && colors[i] != colors[i - 1]) {
                currentMax = 0;
            }
            totalTime += min(currentMax, neededTime[i]);
            currentMax = max(currentMax, neededTime[i]);
        }
        
        return totalTime;
    }
};