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
            swap(nums[ind],nums[i]);
            helper(nums,ind+1,ans,v);
            swap(nums[ind],nums[i]);
         }
         return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v;
        int ind=0;
        helper(nums,ind,ans,v);
        return ans;
    }
};