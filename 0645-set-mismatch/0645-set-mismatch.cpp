class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x :nums)
        {
            mp[x]++;
        }
        int n = nums.size();
        vector<int>ans;
        int a,b;
        for(int i=1;i<=n;i++)
        {
            if(mp.find(i)!=mp.end())
            {
                if(mp[i] > 1)
                {
                    b = i;
                }
            }
            else if(mp.find(i)==mp.end())
            {
                a = i;
            }
        }
        return {b,a};
    }
};