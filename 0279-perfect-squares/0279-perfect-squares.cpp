class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
       if(n==0)  return 0;
       int result=1e9;
       if(dp[n]!=-1)  return dp[n];
       for(int i=1;i*i<=n;i++)
       {
           result=min(result,1+helper(n-i*i,dp));
       }
        return dp[n]=result;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);

    }
};