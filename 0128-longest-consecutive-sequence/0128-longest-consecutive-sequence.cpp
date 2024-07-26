class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=0;
        int count=1;
        if(n==0 || n==1) return n;
        for(int i=0;i<n;i++)
        {
            while(i<n-1 && nums[i]==nums[i+1]) i++;
            if(i<n-1 && nums[i]+1==nums[i+1])
            {
                count++;
            }
            else
            {
                maxi=max(count,maxi);
                count=1;
            }
        }
        maxi=max(count,maxi);
        return maxi;
    }
};