class Solution {
public:
    int helper(vector<int>&nums,int ind,vector<int>&dp)
    {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
         int step1=INT_MIN, step2=INT_MIN;
         step1=nums[ind]+helper(nums,ind-2,dp);
         step2=0+helper(nums,ind-1,dp);
         return dp[ind]=max(step1,step2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return helper(nums,n-1,dp);
    }
};