class Solution {
public:
    int climbStairs(int n) {
      vector<int>dp(n+1,-1);
      int prev2=1;
       int prev1=1;
       int cur=0;
       for(int i=2;i<=n;i++)
       {
        cur=prev1+prev2;
        prev2=prev1;
        prev1=cur;
       }
       return prev1;
    }
};