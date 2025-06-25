class Solution {
public:
    int mod=1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pref(n+1,0);
        vector<int>dp(n+1,0);
        pref[0]=1;
        dp[0]=1;
        int l=0;
        multiset<int>s;
        for(int i=1;i<=n;i++)
        {
            s.insert(nums[i-1]);
            while((*s.rbegin()-*s.begin())>k)
            {
                s.erase(s.find(nums[l]));
                l++;
            }
            dp[i]=(pref[i-1]-((l-1>=0)?pref[l-1]:0)+mod)%mod;
            pref[i]=(pref[i-1]+dp[i])%mod;
        }
        return dp[n];
    }
};