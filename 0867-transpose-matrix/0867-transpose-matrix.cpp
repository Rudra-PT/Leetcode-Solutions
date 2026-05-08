class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>ans;

        for(int j = 0 ; j < cols ; j++){
            vector<int>newRow;
            for(int i = 0 ; i< rows ; i++){
                newRow.push_back(matrix[i][j]);

            }
            ans.push_back(newRow);
        }
        return ans;
    }
};