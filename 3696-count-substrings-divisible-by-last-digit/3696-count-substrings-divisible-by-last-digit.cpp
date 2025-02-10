class Solution {
public:
    long long countSubstrings(string s) {
        long long ans=0;
        int n=s.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(10,vector<int>(10)));
        for(int i=0;i<n;i++)
        {
            int digit=s[i]-'0';
            for(int divisor=1;divisor<=9;divisor++)
            {
                for(int rem=0;rem<divisor;rem++)
                {
                    int newrem=((rem*10)+digit)%divisor;
                    dp[i][divisor][newrem]+=(i==0)?0:dp[i-1][divisor][rem];
                }
                dp[i][divisor][digit%divisor]++;
            }
            ans+=dp[i][digit][0];
        }
        return ans;
    }
};