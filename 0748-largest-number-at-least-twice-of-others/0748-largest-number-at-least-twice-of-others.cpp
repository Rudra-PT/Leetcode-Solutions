class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        
        int maxVal = -1;
        int idx = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] > maxVal){
                maxVal = nums[i];
                idx = i;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i != idx && maxVal < 2 * nums[i]){
                return -1;
            }
        }
        
        return idx;
    }
};
