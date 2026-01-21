class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        long long totalSum = 0;
        for(int x : nums) totalSum += x;
        
        long long leftSum = 0;
        for(int i = 0; i < n; i++) {
            long long rightSum = totalSum - leftSum - nums[i];
            long long leftPart = (long long)nums[i] * i - leftSum;
            long long rightPart = rightSum - (long long)nums[i] * (n - 1 - i);
            
            ans[i] = leftPart + rightPart;
            leftSum += nums[i];
        }
        
        return ans;
    }
};