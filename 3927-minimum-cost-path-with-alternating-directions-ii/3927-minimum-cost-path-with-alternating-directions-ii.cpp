class Solution {
public:
    long long helper(int ind1,int ind2,int m ,int n, vector<vector<int>>&waitcost,int time,vector<vector<vector<long long>>>&dp)
    {
        if(ind1==m-1 && ind2==n-1)
        {
            time++;
            if(time%2==1) return (m*n);
            return waitcost[ind1][ind2]+(m*n);
        }
        if(ind1>=m || ind2>=n) return 1e18;
        long long cost=LLONG_MAX;
        if(dp[ind1][ind2][time%2]!=-1) return dp[ind1][ind2][time%2];
        if(time%2==1)
        {
            if(ind1<m && ind2+1<n)
            {
                
                cost=min(cost,(long long)((ind1+1)*(ind2+1)+helper(ind1,ind2+1,m,n,waitcost,time+1,dp)));
            }
            if(ind1+1<m && ind2<n)
            {
              
              cost=min(cost,(long long)((ind1+1)*(ind2+1)+helper(ind1+1,ind2,m,n,waitcost,time+1,dp)));   
            }
        
        }
       if(time%2==0)
        {
                long long next=helper(ind1,ind2,m,n,waitcost,time+1,dp);
                cost=min(cost,(long long)(waitcost[ind1][ind2]+next));
        }
        return dp[ind1][ind2][time%2]=cost;
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        int a=m*n+1;
        vector<vector<vector<long long>>>dp(m+1,vector<vector<long long>>(n+1,vector<long long>(2,-1)));
        return helper(0,0,m,n,waitCost,1,dp);
    }
};