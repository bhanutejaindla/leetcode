class Solution {
public:
    void helper(int n,string s,vector<string>&ans,int open,int close)
    {
        if(open==n and close==n)
        {
            ans.push_back(s);
            return ;
        }

        if(open<n)
        {
          helper(n,s+'(',ans,open+1,close);
        }
        if(close<open)
        {
          helper(n,s+')',ans,open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        int close=0,open=0;
        helper(n,s,ans,close,open);
        return ans;
    }
};