class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1; 
        unordered_set<int> set2;
        
        int n = nums1.size();
        int m = nums2.size(); 
    
        for(int i = 0; i < max(n, m); i++){
            if (i < n) {
                set1.insert(nums1[i]);
            }
            if (i < m) {
                set2.insert(nums2[i]);
            }
        }
        unordered_map<int, int> mpp;
        for(auto x : set1) {
            mpp[x]++;
        }
        for(auto x : set2) {
            mpp[x]++;
        }

        vector<int> ans;
        for(auto it : mpp) {
            if(it.second == 2) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};