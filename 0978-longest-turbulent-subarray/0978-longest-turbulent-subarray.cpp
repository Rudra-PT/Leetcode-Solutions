class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return n;

        int maxLen = 1;
        int currentStreak = 1;
        char lastDirection = '='; 

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i+1]) {
                if (lastDirection == '<') currentStreak++; 
                else currentStreak = 2; 
                
                lastDirection = '>';
            } 
            else if (arr[i] < arr[i+1]) {
                if (lastDirection == '>') currentStreak++;
                else currentStreak = 2;
                
                lastDirection = '<';
            } 
            else {
                currentStreak = 1;
                lastDirection = '=';
            }
            
            maxLen = max(maxLen, currentStreak);
        }

        return maxLen;
    }
};