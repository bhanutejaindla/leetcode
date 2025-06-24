class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        int l=0,r=0;
        vector<int>rightmin(n,INT_MAX);
        vector<int>rightmax(n,INT_MIN);
        rightmin[n-1]=nums[n-1];
        rightmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
             rightmin[i]=min(rightmin[i+1],nums[i]);
             rightmax[i]=max(rightmax[i+1],nums[i]);
        }
        long long ans=LLONG_MIN;
        for(int i=0;i<=n-m;i++)
        {
            ans=max(ans,rightmin[i+m-1]*(long long)nums[i]);
            ans=max(ans,rightmax[i+m-1]*(long long)nums[i]);
        }
        return ans;

    }
};