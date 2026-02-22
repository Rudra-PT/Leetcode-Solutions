

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0); 
        stack<int> st;        
     
        for (int i = n - 1; i >= 0; i--) {
            int visible = 0;
       
            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
                visible++;
            }

            if (!st.empty()) {
                visible++;
            }
            
   
            ans[i] = visible;

            st.push(heights[i]);
        }
        
        return ans;
    }
};









