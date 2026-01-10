class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> presenceMap;
        for (int x : nums) {
            if (x > 0) {
                presenceMap.insert(x);
            }
        }
        int target = 1;
        while (true) {
            if (presenceMap.find(target) == presenceMap.end()) {
                return target;
            }
            target++;
        }
    }
};