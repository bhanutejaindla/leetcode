class Solution {
public:
    int helper(int ind,vector<int>&dp)
    {
        if(ind==0) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int step1=0,step2=0;
        if(ind>=1)
         step1=helper(ind-1,dp);
        if(ind>=2)
         step2=helper(ind-2,dp);
        return dp[ind]=step1+step2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};