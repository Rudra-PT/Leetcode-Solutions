class Solution {
public:
    int func(int i,int M,int n,vector<int>&suffix,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(2*M>=n-i) return suffix[i];
        if(dp[i][M]!=-1) return dp[i][M];

        int res=0;
        for(int x=1;x<=2*M;x++){
            res=max(res,suffix[i]-func(i+x,max(M,x),n,suffix,dp));
        }
        return dp[i][M]=res;
    }

    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>suffix(n,0);
        suffix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--) suffix[i]=piles[i]+suffix[i+1];
        
        return func(0,1,n,suffix,dp);
    }
};