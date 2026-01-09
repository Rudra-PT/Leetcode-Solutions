class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>copy;
        for(int i = 0 ; i< nums.size(); i++){
            copy.push_back(nums[i]);
        }
        for(int j = 0 ; j< copy.size(); j++){
            nums.push_back(copy[j]);
        }
        return nums;
    }
};