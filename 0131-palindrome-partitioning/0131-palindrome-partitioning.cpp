class Solution {
public:
    bool ispalindrome(int start,int end,string &s)
    {
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else return false;
        }
        return true;
    }
    void helper(int ind,string s,vector<string>&v,vector<vector<string>>&ans)
    {
        if(ind==s.size())
        {
            ans.push_back(v);
            return ;
        }
        for(int i=ind;i<s.size();i++)
        {
           if(ispalindrome(ind,i,s))
           {
            v.push_back(s.substr(ind,i-ind+1));
            helper(i+1,s,v,ans);
            v.pop_back();
           }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string>v;
        vector<vector<string>>ans;
        helper(0,s,v,ans);
        return ans;
    }
};