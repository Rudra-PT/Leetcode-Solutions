class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>answer;
        unordered_map<int,int>digitville;
        for(int i =0 ; i< nums.size(); i++){
            digitville[nums[i]]++;
          }
          for(auto it: digitville){
            if(it.second>=2){
                    answer.push_back(it.first);
            }
          }
         return answer;
    }
};