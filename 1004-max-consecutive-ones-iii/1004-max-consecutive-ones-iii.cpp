class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlength = 0 , l= 0 , r = 0 , zeros = 0;
        int n = nums.size();
        while(r<n){
            if(nums[r]==0) zeros++;
            while(zeros>k){
                if(nums[l]== 0) zeros--;
                l++;
            } 
            maxlength = max(maxlength , r-l+1);
            r++;
        }
         return maxlength;
    }
};