class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        vector<int>ans;
        int n= nums.size();
        for(int i=1;i<=n;i++)
        {
            if(s.find(i)==s.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};