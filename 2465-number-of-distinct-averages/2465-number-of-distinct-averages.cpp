class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<int> unique_sums;
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        
        while (i < j) {
            unique_sums.insert(nums[i] + nums[j]); 
            i++;
            j--;
        }
        
        return unique_sums.size();
    }
};
