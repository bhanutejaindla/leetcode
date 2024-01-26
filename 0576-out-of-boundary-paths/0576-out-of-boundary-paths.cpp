class Solution {
public:
       int mod=1e9+7;
       int helper(int m,int n,int maxMove,int ind1,int ind2,vector<vector<vector<int>>>&dp)
       {
            if(maxMove<0)  return 0;
            if((ind1<0 || ind2<0 || ind1>=m  || ind2>=n))  return 1;
            if(dp[ind1][ind2][maxMove]!=-1)  return dp[ind1][ind2][maxMove];
            long long int left=helper(m,n,maxMove-1,ind1,ind2-1,dp);
            long long int up=helper(m,n,maxMove-1,ind1-1,ind2,dp);
            long long int down=helper(m,n,maxMove-1,ind1+1,ind2,dp);
            long long int right=helper(m,n,maxMove-1,ind1,ind2+1,dp);
            return dp[ind1][ind2][maxMove]=(left+up+down+right)%mod;
       }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
         int ind1=startRow;
         int ind2=startColumn;
     vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
       return  helper(m,n,maxMove,ind1,ind2,dp);
    }
};