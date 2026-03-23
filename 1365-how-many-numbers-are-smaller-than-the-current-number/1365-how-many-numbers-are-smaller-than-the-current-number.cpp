class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>numsc = nums;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        mp[nums[0]] = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != nums[i-1]) mp[nums[i]] = i;
            else mp[nums[i]] = mp[nums[i-1]];
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(mp[numsc[i]]);
        }
        return ans;

    }
};