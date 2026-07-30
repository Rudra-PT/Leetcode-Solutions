class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] == 1) {
                count++;
                maxLen = max(maxLen, count);
            } else {
                count = 0;
            }
        }
        return maxLen;
    }
};
