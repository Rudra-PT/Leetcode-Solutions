class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        set<int>stt;
        for(int i = 0 ; i<n; i++ ){
            stt.insert (nums[i]);
        }
        int org = original;
        for(auto it : stt){
            if(it == org){
                it = org*2;
                org = it;
            }
        } 
        return org;
    }
};