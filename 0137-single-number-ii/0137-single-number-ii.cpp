class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int>mpp;
        int ans;
        for(int i = 0 ; i<nums.size(); i++){
                mpp[nums[i]]++;
        } 
        for(auto it:mpp){
            if(it.second< 3){
            ans =it.first;
            }
        }
        return ans;
    }
};