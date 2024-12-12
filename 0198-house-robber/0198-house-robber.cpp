class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int step1=nums[i];
            if(i>=2) step1+=dp[i-2];
            int step2=0+dp[i-1];
            dp[i]=max(step1,step2);
        }
        return dp[n-1];
    }
};