class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> temp;
        int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            temp.push_back(x);
            for (int j = i + 1; j < n; j++) {
                x += nums[j];
                temp.push_back(x);
            }
        }
        sort(temp.begin(), temp.end());

        long long total_sum = 0;
        for (int i = left - 1; i < right; i++) {
            total_sum = (total_sum + temp[i]) % MOD;
        }

        return total_sum;
    }
};