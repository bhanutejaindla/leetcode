class Solution {
public:
    void helper(string &s)
    {
        int n=s.size();
        int indx=-1;
        for(int i=n-1;i>0;i--)
        {
            if(s[i]<=s[i-1])
            {
              continue;
            }
            else 
            {
                indx=i-1;
                break;
            }
        }
        if(indx==-1) 
        {
            reverse(s.begin(),s.end());
            return ;
        }
        for(int i=n-1;i>indx;i--)
        {
             if((s[i]-'0')>(s[indx]-'0'))
             {
                swap(s[i],s[indx]);
                break;
             }
        }
        reverse(s.begin()+indx+1,s.end());
        return ;
    }
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++)
        {
            s+=to_string(i);
        }
        for(int i=1;i<k;i++)
        {
             helper(s);
        }
        return s;
    }
};