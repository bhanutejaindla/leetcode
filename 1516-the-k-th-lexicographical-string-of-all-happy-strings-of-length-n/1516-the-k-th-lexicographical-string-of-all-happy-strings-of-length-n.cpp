class Solution {
public:
    void helper(string &s,int ind,int k,string &v,int n,vector<string>&vt)
    {
        if(ind>=n)
        {
            vt.push_back(v);
            return ;
        }
       for(int i=0;i<3;i++)
       {
           if(v.empty() || v.back()!=s[i])
           {
            v.push_back(s[i]);
           helper(s,ind+1,k,v,n,vt);
           v.pop_back();
           }
       }
    }
    string getHappyString(int n, int k) {
        string s= "abc";
        string v;
        vector<string>vt;
        helper(s,0,k,v,n,vt);
        for(auto x:vt)
        {
            cout<<x<<endl;
        }
        if(k>vt.size()) return "";
        else return vt[k-1];

    }
};