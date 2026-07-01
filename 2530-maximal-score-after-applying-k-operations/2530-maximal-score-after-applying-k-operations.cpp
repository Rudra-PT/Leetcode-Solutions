class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0; 
        priority_queue<int> pq(nums.begin(), nums.end());

        for (int i = 0; i < k; i++) {
            long long temp = pq.top(); 
            pq.pop(); 
            
            res += temp;
            pq.push((temp + 2) / 3);
        }
        
        return res;
    }
};