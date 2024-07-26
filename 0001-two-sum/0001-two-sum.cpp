class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                return {i,mp[target-nums[i]].second};
            }
            else
            {
                mp[nums[i]].first++;
                mp[nums[i]].second=i;
            }
        }
        return {};
    }
};