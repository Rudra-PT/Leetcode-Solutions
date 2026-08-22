class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int left_neighbor = nums[0]; 
        
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) {
                continue;
            }
            if (nums[i] > left_neighbor && nums[i] > nums[i+1]) {
                count++;
            }
            else if (nums[i] < left_neighbor && nums[i] < nums[i+1]) {
                count++;
            }
            left_neighbor = nums[i];
        }
        
        return count;
    }
};