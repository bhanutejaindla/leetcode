class Solution {
public:
    bool ispredissor(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1) return false;
        int i=0;
        int j=0;
        while(i<s1.size())
        {
            if(j<s2.size() && s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(i==s1.size() && j==s2.size()) return true;
        else return false;
    }
    bool static comp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        sort(words.begin(),words.end(),comp);
        for(int i=0;i<n;i++)
        {
          for(int prev=0;prev<i;prev++)
          {
            if(ispredissor(words[i],words[prev]) and 1+dp[prev]>dp[i])
            {
                dp[i]=1+dp[prev];
            }
          }
          maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};