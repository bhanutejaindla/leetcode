class Solution {
public:
    int helper(vector<int>&arr,int ind ,int k,vector<int>&dp)
    {
         if(ind==arr.size())  return 0;
         if(dp[ind]!=-1)  return dp[ind];
         int maxi=0,ans=0;
         int lim=min(ind+k,int(arr.size()));
         for(int i=ind;i<lim;i++)
         {
             maxi=max(maxi,arr[i]);
             ans=max(ans,maxi*(i-ind+1)+helper(arr,i+1,k,dp));
         }
         return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
       return helper(arr,0,k,dp);
    }
};