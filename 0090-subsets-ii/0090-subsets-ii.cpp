class Solution {
public:
    void helper(vector<int>&nums,int ind,vector<int>&v,set<vector<int>>&s)
    {
        if(ind>=nums.size())
        {
            vector<int>ans=v;
            sort(ans.begin(),ans.end());
            s.insert(ans);
            return ;
        }
        v.push_back(nums[ind]);
        helper(nums,ind+1,v,s);
        v.pop_back();
        helper(nums,ind+1,v,s);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>v;
        helper(nums,0,v,s);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
        
    }
};