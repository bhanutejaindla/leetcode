class Solution {
public:
    
    int helper(vector<int>&nums,int ind,vector<int>&dp)
    {
        
        if(ind>=nums.size())  return 0;
        if(dp[ind]!=-1)  return dp[ind];
        int take=nums[ind]+helper(nums,ind+2,dp);
        int nottake=helper(nums,ind+1,dp);
        return dp[ind]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
         vector<int>dp(n+1,-1);
        return helper(nums,0,dp);
    }
};