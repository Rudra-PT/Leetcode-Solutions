class Solution {
public:
    int findGCD(vector<int>& nums) {
        int x = nums.size();
        sort(nums.begin(),nums.end());
        int m = nums[0];
        int n = nums[x-1];
        return gcd(m,n);
    }
};