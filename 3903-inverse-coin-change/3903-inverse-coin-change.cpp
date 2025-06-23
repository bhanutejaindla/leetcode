class Solution {
public:
    int helper(int ind,int sum,int amount,vector<int>&ans,vector<vector<int>>&dp)
    {
        if(ind>=ans.size()) return 0;
        if(sum > amount ) return 0;
        if(sum==amount)  return 1;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int take=helper(ind,sum+ans[ind],amount,ans,dp);
        int nottake=helper(ind+1,sum,amount,ans,dp);
        return dp[ind][sum]=take+nottake;
    }
    vector<int> findCoins(vector<int>& numWays) {
        int n=numWays.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int amount=i+1;
            int m=ans.size();
            vector<vector<int>>dp(m+1,vector<int>(amount+1,-1));
            int ways=helper(0,0,amount,ans,dp);
            if(ways!=numWays[i])
            {
                ans.push_back(i+1);
                vector<vector<int>>dp1(m+1,vector<int>(amount+1,-1));
                ways=helper(0,0,amount,ans,dp1);
                if(ways!=numWays[i]) return {};
            }
        }
        return ans;
    }
};