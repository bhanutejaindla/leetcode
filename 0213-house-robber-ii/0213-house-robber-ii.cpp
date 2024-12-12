class Solution {
public:
    int helper(vector<int>&temp)
    {
        int n=temp.size();
        vector<int>dp(n,-1);
        dp[0]=temp[0];
        for(int i=1;i<n;i++)
        {
            int step1=temp[i];
            if(i-2>=0) step1+=dp[i-2];
            int step2=0+dp[i-1];
            dp[i]=max(step1,step2);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int>temp1;
        vector<int>temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        int a=helper(temp1);
        int b=helper(temp2);
        return max(a,b);
    }
};