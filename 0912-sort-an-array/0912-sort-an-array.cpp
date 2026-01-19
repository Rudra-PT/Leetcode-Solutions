class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> frequency;
        for (int value : nums) {
            frequency[value]++;
        }

        int writeIndex = 0;
        for (auto [value, count] : frequency) {
            while (count--) {
                nums[writeIndex++] = value;
            }
        }

        return nums;
    }
};