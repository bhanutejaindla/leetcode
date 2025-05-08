class Solution {
public:
    void fun(vector<int>&nums,vector<int>&v,vector<vector<int>>&sol,int ind)
    {
        if(ind>=nums.size())
        {
            sol.push_back(v);
            return ;
        }
        v.push_back(nums[ind]);
        fun(nums,v,sol,ind+1);
        v.pop_back();
        fun(nums,v,sol,ind+1);
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>sol;
        fun(nums,v,sol,0);
        return sol;
    }
};