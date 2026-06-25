class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int squaredDistance = x * x + y * y;
            
            maxHeap.push({squaredDistance, point});
            
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};