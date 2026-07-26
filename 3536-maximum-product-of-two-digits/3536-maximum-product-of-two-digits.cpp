class Solution {
public:
    int maxProduct(int n) {
        n = abs(n); 
        
        vector<long long> ans;
        while(n != 0){
            long long dig = n % 10;
            ans.push_back(dig);
            n = n / 10;
        }
        
        if(ans.size() < 2) return 0; 
        
        sort(ans.begin(), ans.end());
        int m = ans.size();
        int res = ans[m-1] * ans[m-2]; 
        
        return res;
    }
};