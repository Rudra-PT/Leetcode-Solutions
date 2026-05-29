class Solution {
    private:
    int helper(int a){
      int temp = 0;
      while(a){
        temp+=a % 10;
        a= a/10;
      } 
      return temp; 
    }
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i< n; i++){
            nums[i] = helper(nums[i]);
        }
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};