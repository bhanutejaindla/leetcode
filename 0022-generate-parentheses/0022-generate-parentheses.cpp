class Solution {
public:
    void fun(int n,string s,vector<string>&v,int openp,int closep)
    {
        if(openp==n && closep==n)
        {
            v.push_back(s);
            return ;
        }
        if(openp<n)
        {
            fun(n,s+'(',v,openp+1,closep);
        }
        if(openp>closep)
        {
            fun(n,s+')',v,openp,closep+1);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>v;
        fun(n,s,v,0,0);
        return v;
    }
};