class Solution {
public:
    void helper(int ind,vector<int>&nums,int k,int sum,vector<int>&v,vector<vector<int>>&ans)
    {
       if(k==0 and sum==0)
       {
         ans.push_back(v);
         return ;
       }
       if(k<0 || ind>=nums.size() || sum<0)
       {
        return ;
       }
       v.push_back(nums[ind]);
       helper(ind+1,nums,k-1,sum-nums[ind],v,ans);
       v.pop_back();
       helper(ind+1,nums,k,sum,v,ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums{1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>v;
        helper(0,nums,k,n,v,ans);
        return ans;
    }
};