#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long validCount = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto low_iter = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto high_iter = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            validCount += (high_iter - low_iter);
        }
        
        return validCount;
    }
};