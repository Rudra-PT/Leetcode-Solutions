class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      priority_queue<int, std::vector<int>, std::greater<int>> min_heap(nums.begin() , nums.end());
        int n = nums.size();
      for(int i = 0 ; i < n ; i++){
        nums[i]= min_heap.top();
        min_heap.pop();
      }
      return nums;

    }
};