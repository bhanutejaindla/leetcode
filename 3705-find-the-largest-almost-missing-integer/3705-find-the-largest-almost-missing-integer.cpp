class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
       map<int,int>mp;
       int n=nums.size();
       for(int i=0;i<=n-k;i++)
       {
        unordered_set<int>s;
         for(int j=i;j<i+k;j++)
         {
            s.insert(nums[j]);
         }
         for(auto x:s)
         {
            mp[x]++;
         }
       }
       int maxi=-1;
       for(auto x:mp)
       {
         if(x.second==1)
         {
            maxi=max(maxi,x.first);
         }
       }
       return maxi;
    }
};