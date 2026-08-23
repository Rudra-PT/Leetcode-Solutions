class Solution {
private:
    bool helper(int n){
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(auto num : nums){
            mpp[num]++;
        }
        
        for(auto it : mpp){
            bool flag = helper(it.second);
            if (flag) {
                return true;
            }
        }
        
        return false; 
    }
};
