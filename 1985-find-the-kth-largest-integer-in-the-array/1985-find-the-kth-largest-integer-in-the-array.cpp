class Solution {
public:
    struct CompareNumericStrings {
        bool operator()(const string& a, const string& b) {
            if (a.length() != b.length()) {
                return a.length() > b.length(); 
            }
            return a > b;
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, CompareNumericStrings> minHeap;
        
        for (const string& num : nums) {
            minHeap.push(num);
    
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};