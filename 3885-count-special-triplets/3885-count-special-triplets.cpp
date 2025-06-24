class Solution {
public:
    int mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp,mp1;
        long long int zeroes=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(nums[i]==0)  zeroes++;
        } 
        // if(zeroes==n){
        // long long int ans=((zeroes*(zeroes-1)*(zeroes-2))/6)%mod;
        // return ans;
        // }
        long ans=0;
        for(int j=0;j<nums.size();j++)
        {
              int a=nums[j]*2;
              if(mp1.find(a)!=mp.end())
              {
                  long l=mp1[a];
                  long r=mp[a]-mp1[a];
                  if(a==nums[j]) r-=1;
                  ans+=(l*r)%mod;

              }
              mp1[nums[j]]++;
        }
        return ans%mod;

    }
};