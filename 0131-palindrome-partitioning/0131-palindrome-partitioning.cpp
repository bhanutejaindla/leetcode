class Solution {
public:
    bool palindrome(string &s,int start,int end)
    {
        while(start<=end)
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
    void helper(string &s,vector<string>&v,vector<vector<string>>&ans,int ind)
    {
        if(ind>=s.size())
        {
            ans.push_back(v);
            return ;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(palindrome(s,ind,i))
            {
                v.push_back(s.substr(ind,i-ind+1));
                helper(s,v,ans,i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>v;
        vector<vector<string>>ans;
        helper(s,v,ans,0);
        return ans;
    }
};