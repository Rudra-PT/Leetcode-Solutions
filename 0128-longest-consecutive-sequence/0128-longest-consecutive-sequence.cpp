class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>mpp;
        for(int i = 0 ; i< n ; i++){
            mpp[nums[i]]++;
        }
        int maxsez=0;

        for(auto it : mpp) {
            int num = it.first; 
            if(mpp.find(num - 1) == mpp.end()) {
                
                int currentNum = num;
                int currentStreak = 1;

                while(mpp.find(currentNum + 1) != mpp.end()) {
                    currentNum++;
                    currentStreak++;
                }

                maxsez = max(maxsez, currentStreak);
            }
        }
        
        return maxsez;
    }
};