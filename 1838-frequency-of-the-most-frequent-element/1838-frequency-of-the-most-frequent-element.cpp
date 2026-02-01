class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = 0, totalSum = 0;
        int maxFreq = 0;

        for (int right = 0; right < nums.size(); ++right) {
            totalSum += nums[right];
            while ((long long)nums[right] * (right - left + 1) - totalSum > k) {
                totalSum -= nums[left];
                left++;
            }

            maxFreq = max(maxFreq, (int)(right - left + 1));
        }

        return maxFreq;
    }
};