class Solution {
public:
    int helper(int i,int m,vector<int>&p,vector<vector<int>>&dp)
    {
        if(i>=p.size()) return 0;
        int tot=0;
        int ans=INT_MIN;
        if(dp[i][m]!=-1) return dp[i][m];
        for(int j=0;j<2*m;j++)
        {
            if(i+j<p.size()) tot+=p[i+j];
            ans=max(ans,tot-helper(i+j+1,max(m,j+1),p,dp));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
       int sum=0;
       for(auto a:piles) sum+=a;
        int n=piles.size();
       vector<vector<int>>dp(n+1,vector<int>(2*n+2,-1));
       int diff=helper(0,1,piles,dp);
       return (sum+diff)/2;
    }
};