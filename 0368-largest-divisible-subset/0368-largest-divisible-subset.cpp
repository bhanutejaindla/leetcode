class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        int maxi=1;
        int lastindex=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(maxi<dp[i])
            {
                maxi=dp[i];
                lastindex=i;
            }
        }
        vector<int>list;
        list.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex)
        {
            lastindex=hash[lastindex];
            list.push_back(nums[lastindex]);
        }
        reverse(list.begin(),list.end());
        return list;   
    }
};