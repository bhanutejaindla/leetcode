class Solution {
public:
    int helper(vector<int>&nums,int ind,int k,int n,vector<vector<int>>&dp)
    {
         if(k<0) return INT_MAX;
         if(ind<n && k==0) return INT_MAX;
        if(ind>=n)
        {
            if(k==0) return 0;
            return INT_MAX;
        } 
        if(dp[ind][k]!=-1) return dp[ind][k]; 
        int xori = 0;
        int ans=INT_MAX;
        for(int i=ind;i<n;i++)
        {
                 xori^=nums[i];
                 ans=min(ans,max(xori,helper(nums,i+1,k-1,n,dp)));
        }
        return dp[ind][k]=ans;
    }
    int minXor(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return helper(nums,0,k,n,dp);
    }
};