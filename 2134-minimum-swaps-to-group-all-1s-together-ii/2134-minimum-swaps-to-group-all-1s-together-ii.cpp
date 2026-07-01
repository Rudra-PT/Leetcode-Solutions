class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int num : nums) {
            if (num == 1) k++;
        }
        
        if (k == 0 || k == n) return 0;
        
        int current_zeros = 0;
        int min_swaps = n;
         
        for (int i = 0; i < k; i++) {
            if (nums[i] == 0) {
                current_zeros++;
            }
        }
        
        min_swaps = current_zeros;
        for (int i = k; i < n + k - 1; i++) {
            if (nums[(i - k) % n] == 0) {
                current_zeros--;
            }
            if (nums[i % n] == 0) {
                current_zeros++;
            }
            min_swaps = min(min_swaps, current_zeros);
        }
        
        return min_swaps;
    }
};