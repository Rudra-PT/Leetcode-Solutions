class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        long long currentSum = 0;
        long long targetSum = (long long)k * threshold;
        
        for (int i = 0; i < k; i++) {
            currentSum += arr[i];
        }
        if (currentSum >= targetSum) {
            count++;
        }
        for (int i = k; i < arr.size(); i++) {
            currentSum += arr[i];
            currentSum -= arr[i - k];
            
            if (currentSum >= targetSum) {
                count++;
            }
        }
        
        return count;
    }
};