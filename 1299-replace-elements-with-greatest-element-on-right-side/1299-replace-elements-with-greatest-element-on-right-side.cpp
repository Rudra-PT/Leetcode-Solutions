class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRight = -1;

        for (int i = n - 1; i >= 0; i--) {
            int currentVal = arr[i]; 
            arr[i] = maxRight;  
            
            if (currentVal > maxRight) {
                maxRight = currentVal;
            }
        }
        
        return arr;
    }
};