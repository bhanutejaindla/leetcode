class Solution {
public:
   bool palindrome(string s,int ind,int i)
   {
        while(ind<=i)
        {
            if(s[ind]==s[i])
            {
                ind++;
                i--;
            }
            else return false;
        }
        return true;
   }
    void helper(string &s,int ind,vector<vector<string>>&ans,vector<string>&v)
    {
       if(ind==s.size())
       {
          ans.push_back(v);
          return ;
       }
       for(int i=ind;i<s.size();i++)
       {
          if(palindrome(s,ind,i))
          {
            string x=s.substr(ind,i-ind+1);
            v.push_back(x);
            helper(s,i+1,ans,v);
            v.pop_back();
          }
       }
       return ;
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>v;
        helper(s,0,ans,v);
        return ans;
    }
};