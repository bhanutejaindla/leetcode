class Solution {
public:
    void helper(int n,int ind,int k,string s,string x,vector<string>&v)
    {
        if(ind>=n)
        {
            v.push_back(x);
            return ;
        }
        for(int i=0;i<3;i++)
        {
          if(x.empty() || x.back()!=s[i])
          {
            x.push_back(s[i]);
            helper(n,ind+1,k,s,x,v);
            x.pop_back();
          }
        }
    }
    string getHappyString(int n, int k) {
        string s = "abc";
        string x = "";
        vector<string>v;
        helper(n,0,k,s,x,v);
        sort(v.begin(),v.end());
        if(v.size() < k) return "";
        return v[k-1];
    }
};