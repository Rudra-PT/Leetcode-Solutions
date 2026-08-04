class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;

        for (int i = 0; i < n-1; i++) {
            if (nums[i + 1] == nums[i]) {
                continue;
            }
            while (nums[i+1]!=nums[i]+1){
                res.push_back(nums[i]+1);
                nums[i]=nums[i]+1;
            }
        }
        return res;
    }
};