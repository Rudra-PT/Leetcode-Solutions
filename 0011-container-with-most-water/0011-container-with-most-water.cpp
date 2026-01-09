class Solution {
public:
    int maxArea(vector<int>& height) {
     int  n = height.size();
      int maxWater= 0 ; 
      int left  = 0 ;
      int right = n-1;
      while(left<right){
        int w = right - left;
        int ht = min(height[left], height[right]);
        int currWater  = w * ht;
        maxWater = max(maxWater , currWater);

        if(height[left] < height[right]) left++;
        else right--; 
      }
      return maxWater;
    
    }
};