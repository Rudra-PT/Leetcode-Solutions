class Solution {
public:
 int digitsSum(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;        
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = digitsSum(nums[i]);
        }
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            result = min(result, nums[i]);
        }
        
        return result;
    }
   
};