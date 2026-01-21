class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int x : nums){
            mpp[x]++;
        }
        vector<int> freq;
        for(auto it : mpp){
            freq.push_back(it.second);
        }
        
        int ans = 0;
        for(int i = 0; i < freq.size(); i++) {
            int count = freq[i];
            
            if(count == 1) return -1;
            
            while(count > 0) {
                if (count % 3 == 0) {
                    count -= 3;
                    ans++;
                } else {
                    count -= 2;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};