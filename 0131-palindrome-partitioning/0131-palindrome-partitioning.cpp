class Solution {
public:
    bool isPalindrome(int start,int end,string s)
    {
            while(start<end)
            {
                if(s[start]!=s[end]) return false;
                start++;
                end--;
            }
            return true;
    }
    void fun(int ind,string s,vector<string>&ans,vector<vector<string>>&v)
    {
        if(ind>=s.size())
        {
            v.push_back(ans);
            return ;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(isPalindrome(ind,i,s))
            {
                ans.push_back(s.substr(ind,i-ind+1));
                fun(i+1,s,ans,v);
                ans.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        vector<vector<string>>v;
        fun(0,s,ans,v);
        return v;
    }
};