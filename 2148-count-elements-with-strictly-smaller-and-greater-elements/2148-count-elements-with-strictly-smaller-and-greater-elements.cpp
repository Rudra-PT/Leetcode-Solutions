class Solution {
public:
    int countElements(vector<int>& nums) {
     sort(nums.begin(), nums.end());
       int n = nums.size();
       int gtr = nums[n-1];
       int sml = nums[0]; 
       int count = 0 ;

       for(int i = 0 ; i <n ; i++){
        if(nums[i]> sml && nums[i]<gtr) count++;
       }
       return count;
    }
};