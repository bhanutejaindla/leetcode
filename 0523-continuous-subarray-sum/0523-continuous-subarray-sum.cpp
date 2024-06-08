class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
       unordered_map<int,int>mp;
       mp[0]=0;
       int prefixsum=0;
       for(int i=0;i<n;i++)
       {
           prefixsum=(prefixsum+nums[i])%k;
           if(mp.find(prefixsum)!=mp.end())
           {
            if(i+1-mp[prefixsum]>=2) return true;
           }
           else
           {
            mp[prefixsum]=i+1;
           }
       }
       return false;
    }
};