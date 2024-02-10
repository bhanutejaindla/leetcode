class Solution {
public:
    int check(string &s,int l,int h)
    {
        int x=0;
        while(l>=0 && h<s.size())
        {
            if(s[l]==s[h]) {x++;
            l--,h++;}
            else break;
        }
        return x;
    }
    int helper(string &s)
    {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
        ans+=check(s,i,i);
        ans+=check(s,i,i+1);
        }
        return ans;
    }
    int countSubstrings(string s) {
        
        return helper(s);
    }
};