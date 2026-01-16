class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mpp;
        for(char c : s){
            mpp[c]++;
        }
        
        int maxOdd = INT_MIN; 
        int minEven = INT_MAX; 
        
        for(auto it : mpp){
            if(it.second % 2 != 0){ 
                maxOdd = max(maxOdd, it.second);
            }
            else{ 
                minEven = min(minEven, it.second);
            }
        }
        return maxOdd - minEven;
    }
};