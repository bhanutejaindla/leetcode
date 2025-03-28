class Solution {
public:
    void helper(int ind,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans)
    {
        if(ind>=nums.size())
        {
            ans.push_back(v);
            return ;
        }
        v.push_back(nums[ind]);
        helper(ind+1,nums,v,ans);
        v.pop_back();
        helper(ind+1,nums,v,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int>v;
       vector<vector<int>>ans;
       helper(0,nums,v,ans); 
       return ans;
    }
};
