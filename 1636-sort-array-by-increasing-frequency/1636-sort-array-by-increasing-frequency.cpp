class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<pair<int, int>> res;

        for (auto num : nums) {
            mpp[num]++;
        }
        for (auto it : mpp) {
            res.push_back({it.first, it.second});
        }
        sort(res.begin(), res.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second; 
        });

        vector<int> ans;
        for (auto& p : res) {
            ans.insert(ans.end(), p.second, p.first); 
        }
        
        return ans;
    }
};