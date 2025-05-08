class Solution {
public:
    void fun(vector<int>&candidates,int target,vector<int>&ans,vector<vector<int>>&v,int ind)
    {
        if(target<0)
        {
            return ;
        }
        if(ind>=candidates.size())
        {
           if(target==0)
           {
              v.push_back(ans);
              return ;
           }
           else
           {
            return ;
           }
        }
        ans.push_back(candidates[ind]);
        fun(candidates,target-candidates[ind],ans,v,ind);
        ans.pop_back();
        fun(candidates,target,ans,v,ind+1);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>>v;
        fun(candidates,target,ans,v,0);
        return v;
    }
};