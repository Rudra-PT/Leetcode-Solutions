class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int Sum = 0;

        for(int i = 0 ; i < n ; i++){
            Sum+=nums[i];
            maxSum = max(maxSum,Sum);
            if(Sum<0){
                Sum = 0 ;
            }

        }
    return maxSum;

    }
};