class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int ,int>mpp;

        int i = 0 ; 
        int j = i+1;

        while(j<n){
            int temp = nums[i]+nums[j];
            mpp[temp]++;
            i++;
            j++;
        }
        for(auto it : mpp){
            if(it.second >=2){
                return true;
            }
        }
        return false;
    }
};