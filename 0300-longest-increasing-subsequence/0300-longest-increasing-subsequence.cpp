class Solution {
public:
    int helper(vector<int>&nums,int prev,int ind,vector<vector<int>>&dp)
    {
        if(ind>=nums.size())
        {
            return 0;
        }
        if(dp[prev+1][ind]!=-1) return dp[prev+1][ind];
        int take=0,nottake=0;
        if(prev==-1 || nums[prev]<nums[ind])
        {
            take=1+helper(nums,ind,ind+1,dp);
        }
        nottake=helper(nums,prev,ind+1,dp);
        return dp[prev+1][ind]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(nums,prev,0,dp);
    }
};