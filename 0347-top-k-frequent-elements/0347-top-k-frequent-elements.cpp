class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int ,int> mpp;
        for(int num : nums) mpp[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for(auto& [num , freq] : mpp){
            min_heap.push({freq , num});
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        vector<int>ans;
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};