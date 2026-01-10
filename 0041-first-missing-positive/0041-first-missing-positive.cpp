class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> mpp;
        for (int x : nums) {
            if (x > 0) {
                mpp.insert(x);
            }
        }
        int target = 1;
        while (true) {
            if (mpp.find(target) == mpp.end()) {
                return target;
            }
            target++;
        }
    }
};