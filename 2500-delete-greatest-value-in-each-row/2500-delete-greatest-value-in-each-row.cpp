class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++)
            sort(grid[i].begin(), grid[i].end());
        int sum = 0;
        int mxEle;
        int m = grid[0].size();
        for (int j = m - 1; j >= 0; j--) {
            mxEle = INT_MIN;
            for (int i = 0; i < n; i++) {
                mxEle = max(mxEle, grid[i][j]);
            }
            sum += mxEle;
        }
        return sum;
    }
};