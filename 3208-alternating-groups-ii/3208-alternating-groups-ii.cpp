class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        int current_streak = 1;
        
        for (int i = 1; i < n + k - 1; i++) {
            int current_idx = i % n;
            int prev_idx = (i - 1) % n;
            
            if (colors[current_idx] != colors[prev_idx]) {
                current_streak++;
            } else {
                current_streak = 1;
            }
            if (current_streak >= k) {
                count++;
            }
        }
        
        return count;
    }
};