class Solution {
public:
    void helper(vector<int>&nums,vector<int>&v,set<vector<int>>&ans,int ind)
    {
        if(ind>=nums.size())
        {
            ans.insert(v);
            return ;
        }
        v.push_back(nums[ind]);
        helper(nums,v,ans,ind+1);
        v.pop_back();
        helper(nums,v,ans,ind+1);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        set<vector<int>>ans;
        helper(nums,v,ans,0);
        vector<vector<int>>a(ans.begin(),ans.end());
        return a;
    }
};