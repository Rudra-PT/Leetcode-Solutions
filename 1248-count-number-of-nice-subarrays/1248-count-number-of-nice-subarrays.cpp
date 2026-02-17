
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int oddCount = 0;
        int ans = 0;
        int countValidStarts = 0;

        for (right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1) {
                oddCount++;
                countValidStarts = 0;
            }
            while (oddCount == k) {
                countValidStarts++;
                if (nums[left] % 2 == 1) {
                    oddCount--;
                }
                left++;
            }
            ans += countValidStarts;
        }

        return ans;
    }
};