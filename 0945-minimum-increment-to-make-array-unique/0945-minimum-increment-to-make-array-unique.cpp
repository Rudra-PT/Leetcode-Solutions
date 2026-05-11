class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] <= nums[i]) {
                int newValue = nums[i] + 1;
                count += (newValue - nums[i + 1]);
                nums[i + 1] = newValue;
            }
        }
        return count;
    }
};