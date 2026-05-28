class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0); 
        for (int num : nums) {
            freq[num]++;
        }

        fill(nums.begin(), nums.begin() + freq[0], 0);
        fill(nums.begin() + freq[0], nums.begin() + freq[0] + freq[1], 1);
        fill(nums.begin() + freq[0] + freq[1], nums.end(), 2);
    }
};