class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int repeated = 0, missed = 0;

        for (int i = 1; i <= nums.size(); i++) {
            if (freq[i] == 2) repeated = i; 
            if (freq[i] == 0) missed = i;    
        }

        return {repeated, missed};
    }
};