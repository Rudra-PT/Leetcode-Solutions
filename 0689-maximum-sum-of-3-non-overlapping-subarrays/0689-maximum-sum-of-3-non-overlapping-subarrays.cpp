class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n-k+1, 0);
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        prefix[0] = sum;

        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i-k];
            prefix[i-k+1] = sum;
        }

        
        vector<int> left(prefix.size(), 0);
        int maxi = 0;
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] > prefix[maxi]) {
                maxi = i;
            }
            left[i] = maxi;
        }

        vector<int> right(prefix.size(), 0);
        maxi = prefix.size() - 1;
        for (int i = prefix.size() - 1; i >= 0; i--) {
            if (prefix[i] >= prefix[maxi]) {
                maxi = i;
            }
            right[i] = maxi;
        }

        
        vector<int> result(3, 0);
        int maxSum = 0;
        for (int mid = k; mid < prefix.size() - k; mid++) {
            int l = left[mid - k];
            int r = right[mid + k];
            int total = prefix[l] + prefix[mid] + prefix[r];
            if (total > maxSum) {
                maxSum = total;
                result = {l, mid, r};
            }
        }

        return result;
    }
};