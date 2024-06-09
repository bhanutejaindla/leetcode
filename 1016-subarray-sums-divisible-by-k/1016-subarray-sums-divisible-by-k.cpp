class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int cnt=0,pref=0;
        //8 17 24 32 41
        //0  1 0 0 1 
        for(int i=0;i<n;i++)
        {
            while(nums[i]<=0)
            {
                 nums[i]+=k;
            }
            pref=(pref+nums[i])%k;
            if(mp.find(pref)!=mp.end())
            {
                mp[pref]++;
                cnt+=(mp[pref]-1);
            }
            else
            {
                mp[pref]++;
                if(pref==0)  cnt++;
            }
        }
        if(mp[0]>1) cnt+=(mp[0]-1);
        return cnt;
    }
};