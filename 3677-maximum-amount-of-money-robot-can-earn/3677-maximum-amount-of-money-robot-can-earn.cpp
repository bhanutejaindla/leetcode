class Solution {
public:
    int helper(int ind1,int ind2,int n,int m,int cnt,vector<vector<int>>&coins,vector<vector<vector<int>>>&dp)
    {
       if(ind1==n-1 && ind2==m-1)
       {
         if(coins[ind1][ind2]<0)
         {
            return (cnt<2)?0:coins[ind1][ind2];
         }
         else
         {
            return coins[ind1][ind2];
         }
       }
       if(dp[ind1][ind2][cnt]!=INT_MIN) return dp[ind1][ind2][cnt];
       if(ind1>=n || ind2>=m) return -1e9;
        
       int bottom=INT_MIN;
       int right=INT_MIN;
       if(coins[ind1][ind2]<0)
       {
          if(cnt<2)
          {
            bottom=helper(ind1+1,ind2,n,m,cnt+1,coins,dp);
            right=helper(ind1,ind2+1,n,m,cnt+1,coins,dp);
          }
       }
       bottom=max(bottom,coins[ind1][ind2]+helper(ind1+1,ind2,n,m,cnt,coins,dp));
       right=max(right,coins[ind1][ind2]+helper(ind1,ind2+1,n,m,cnt,coins,dp));
       return dp[ind1][ind2][cnt]=max(bottom,right);  
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(3,INT_MIN)));
       return  helper(0,0,n,m,0,coins,dp);
    }
};