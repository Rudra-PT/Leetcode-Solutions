class Solution {
public:
    int maxDistance(vector<int>& colors) {
     int maxLen = INT_MIN;
     int n = colors.size();
     for(int i = 0 ; i< n-1 ;i++){
        for(int j = i+1 ; j < n ;j++){
            if(colors[i]!=colors[j]){
                maxLen = max(maxLen , j-i);
            }
        }
     }   
     return maxLen;
    }
};