class Solution {
public:
    void helper(vector<int>&candidates,int ind,int target,vector<int>&v,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        if(ind>=candidates.size() || target<0)
        {
            return ;
        }
         v.push_back(candidates[ind]);
         helper(candidates,ind,target-candidates[ind],v,ans);
       
       v.pop_back();
       helper(candidates,ind+1,target,v,ans);
       return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       vector<int>v;
       helper(candidates,0,target,v,ans); 
       return ans;
    }
};;
