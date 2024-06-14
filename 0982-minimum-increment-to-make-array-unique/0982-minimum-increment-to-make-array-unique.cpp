class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<int>v;
         int n=nums.size();
         unordered_map<int,int>mp;
         for(int i=0;i<n;i++)
         {
            mp[nums[i]]++;
            if(mp[nums[i]]>1) v.push_back(nums[i]);
         }
         
         int mini=*min_element(nums.begin(),nums.end());
         int maxi=*max_element(nums.begin(),nums.end());
         int ind=0,sum=0;
         for(int i=mini;i<=(2*maxi+1) && ind<v.size();i++)
         {
            if(mp[i]==0 && i>v[ind])
            {
               sum+=(i-v[ind]);
               ind++;
            }
         }
         return sum;
    }
};