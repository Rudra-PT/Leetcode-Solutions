class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int m = n - 1;
        if (n < 2) return false;

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        if (mpp.size() != m) return false;

        for (int i = 1; i < m; i++) {
            if (mpp[i] != 1) return false;
        }
        if (mpp[m] != 2) return false;

        return true;
    }
};