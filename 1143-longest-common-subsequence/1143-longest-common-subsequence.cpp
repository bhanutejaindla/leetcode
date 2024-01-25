class Solution {
public:
    int helper(string &s1,string s2,int ind1,int ind2,vector<vector<int>>&dp)
    {
        
        if(ind1<0 || ind2<0)  return 0;
        if(dp[ind1][ind2]!=-1)  return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])
        {
            return dp[ind1][ind2]=1+helper(s1,s2,ind1-1,ind2-1,dp);
        }
        return dp[ind1][ind2]=max(helper(s1,s2,ind1-1,ind2,dp),helper(s1,s2,ind1,ind2-1,dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(text1,text2,m-1,n-1,dp);
    }
};