class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long pref[n];
        pref[0]=0;
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i-1];
        }
        long long suf[n];
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+nums[i];
        }
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(pref[i]>=suf[i]) cnt++;
        }
        return cnt;
    }
};