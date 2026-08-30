class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int minIdx = 0;
        int maxIdx = 0;

        for (int k = 1; k < n; k++) {
            if (nums[k] < nums[minIdx]) minIdx = k;
            if (nums[k] > nums[maxIdx]) maxIdx = k;
        }

        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        int opt1 = j + 1;          
        int opt2 = n - i;         
        int opt3 = (i + 1) + (n - j); 

        return min({opt1, opt2, opt3});
    }
};