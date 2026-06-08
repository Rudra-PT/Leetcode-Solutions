class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lower, equal, greater;

        for(int num : nums) {
            if(num < pivot) lower.push_back(num);
            else if(num == pivot) equal.push_back(num);
            else greater.push_back(num);
        }
        
        lower.insert(lower.end(), equal.begin(), equal.end());
        lower.insert(lower.end(), greater.begin(), greater.end());

        return lower;
    }
};
