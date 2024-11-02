class Solution {
public:
    void helper(vector<int>&nums,int ind,vector<vector<int>>&ans,vector<int>&v)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        for(int i=ind;i<nums.size();i++)
         {
            swap(nums[i],nums[ind]);
            helper(nums,i+1,ans,v);
            swap(nums[i],nums[ind]);
         }
         return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v;
        helper(nums,0,ans,v);
        return ans;
    }
};