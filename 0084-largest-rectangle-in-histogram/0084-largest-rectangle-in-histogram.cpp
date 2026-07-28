class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s; 
        int maxArea = 0;
        int n = heights.size();
    
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int currentHeight = heights[s.top()];
                s.pop();
                
                int width;
                if (s.empty()) {
                    width = i;
                } else {
                    width = i - s.top() - 1;
                }
                
                maxArea = max(maxArea, currentHeight * width);
            }
            
            s.push(i);
        }
        
        while (!s.empty()) {
            int currentHeight = heights[s.top()];
            s.pop();
            
            int width;
            if (s.empty()) {
                width = n;
            } else {
                width = n - s.top() - 1;
            }
            
            maxArea = max(maxArea, currentHeight * width);
        }
        
        return maxArea;
    }
};