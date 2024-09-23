class Solution {
public:
    int helper(int ind,string &s,unordered_map<string,int>&mp,vector<int>&dp)
    {
        if(ind>=s.size()) return 0;
        string currstr="";
        int size=s.size();
        if(dp[ind]!=-1) return dp[ind];
        for(int currind=ind;currind<s.size();currind++)
        {
            currstr.push_back(s[currind]);
            int count=mp.count(currstr)?0:currstr.size();
            count+=helper(currind+1,s,mp,dp);
            size=min(size,count);
        }
        return dp[ind]=size;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>mp;
        for(auto &x:dictionary)
        {
            mp[x]++;
        }
        int n=s.size();
        vector<int>dp(n+1,-1);
       return  helper(0,s,mp,dp);
        
    }
};