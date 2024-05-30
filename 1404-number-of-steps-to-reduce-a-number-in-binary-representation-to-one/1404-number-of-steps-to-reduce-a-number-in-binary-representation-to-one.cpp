class Solution {
public:
    void add(string &s)
    {
        string ans="";
        int carry=1;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int sum=(s[i]-'0')+carry;
            ans+=to_string(sum%2);
            carry=sum/2;
        }
        if(carry==1) ans+=to_string(carry);
        s=ans;
    }
    int numSteps(string s) {
         int count=0;
         reverse(s.begin(),s.end());
         while(true)
         {
            if(s[0]=='1' && s.size()>1)
            {
                add(s);
                count++;
            }
           else  if(s[0]=='0' && s.size()>1)
            {
                reverse(s.begin(),s.end());
                 s.pop_back();
                 reverse(s.begin(),s.end());
                 count++;
            }
            if(s.size()==1 && s[0]=='1') break;
         }
         return count;
    }
};