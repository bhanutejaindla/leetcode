class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right)
        {
            if(v[left].first+v[right].first==target)
            {
                return {v[left].second,v[right].second};
            }
            else if(v[left].first+v[right].first>target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return {};
        
    }
};