class Solution {
public:
    int maxArea(vector<int>& nums) {
       int n = nums.size();
       int i = 0 ;
       int j = n-1;
       int maxArea = 0;
       while(i<j){
        int sides = min(nums[i],nums[j]);
        int b = j-i;
        maxArea = max(maxArea , sides*b);
        if(nums[i]<nums[j]) i++;
        else j--;
       }
       return maxArea;
    }
};