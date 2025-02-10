class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(i-nums[i]);
        }
        unordered_map<int,int>mp;
        long long v=0;
        for(int i=0;i<ans.size();i++)
        {
            if(mp.find(ans[i])!=mp.end())
            {
               v+=mp[ans[i]];
            }
            mp[ans[i]]++;
        }
        long k=n-1;
        return (k*(k+1))/2 -v;
    }
};