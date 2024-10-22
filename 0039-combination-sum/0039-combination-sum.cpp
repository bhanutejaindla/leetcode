class Solution {
public:
    void helper(vector<int>&candidates,int ind,int target,set<vector<int>>&s,vector<int>&v)
    {
        if(ind>=candidates.size())
        {
            if(target==0)
            {
                s.insert(v);
            }
            return ;
        }
        if(candidates[ind]<=target)
        {
            v.push_back(candidates[ind]);
            helper(candidates,ind,target-candidates[ind],s,v);
            v.pop_back();
        }
        helper(candidates,ind+1,target,s,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>s;
        vector<int>v;
        helper(candidates,0,target,s,v);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};