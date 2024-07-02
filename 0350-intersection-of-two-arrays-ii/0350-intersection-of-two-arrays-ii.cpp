class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int,int>mp;
         for(auto x:nums2) mp[x]++;
         vector<int>v;
         for(auto x:nums1)
         {
            if(mp.find(x)!=mp.end() && mp[x]>0) {  v.push_back(x);
            mp[x]--;
            }
         }
         return v;
    }
};