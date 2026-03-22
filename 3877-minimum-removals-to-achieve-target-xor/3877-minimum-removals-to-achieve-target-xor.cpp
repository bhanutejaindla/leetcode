class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size(),MAXX=1e5;
        vector<int> dp(MAXX+1,-1); // dp[i]=max number of elements to take such that XOR = i
        dp[0]=0;
        for(int x:nums){
            vector<int> ndp=dp;
            for(int i=0;i<=MAXX;i++){
                if(dp[i]!=-1){ // [....] = XOR = i
                    ndp[i^x]=max(ndp[i^x],dp[i]+1);
                }
            }
            dp=ndp;
        }
        if(dp[target]==-1) return -1;
        return n-dp[target];
    }
};