class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int num1 = nums[0] *nums[1];
        int num2 = nums[n-1] * nums[n-2];
        return num2-num1;
    }
};