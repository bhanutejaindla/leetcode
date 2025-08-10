class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end());
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=v[i])
            {
                a.push_back(nums[i]);
            }
        }
        if(a.empty()) return 0;
        int ans=a[0];
        for(int i=1;i<a.size();i++)
        {
            ans&=a[i];
        }
        return ans;
    }
};