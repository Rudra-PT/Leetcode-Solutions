class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        while(k > 0) {
            int temp = pq.top();
            pq.pop();
    
            int remaining_gifts = sqrt(temp); 
            pq.push(remaining_gifts);
            
            k--;
        }
        long long totalSum = 0;
        while(!pq.empty()){
            totalSum += pq.top();
            pq.pop();
        }
        
        return totalSum;
    }
};