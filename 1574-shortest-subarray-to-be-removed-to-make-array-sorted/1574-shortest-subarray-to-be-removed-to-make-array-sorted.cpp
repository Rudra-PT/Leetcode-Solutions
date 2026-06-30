class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }

        if (right == 0) return 0;
    
        int min_removed = right;
        for (int i = 0; i < n; i++) {

            if (i > 0 && arr[i - 1] > arr[i]) {
                break;
            }
        
            auto it = lower_bound(arr.begin() + right, arr.end(), arr[i]);

            int j = distance(arr.begin(), it);
            min_removed = min(min_removed, j - i - 1);
        }
        
        return min_removed;
    }
};