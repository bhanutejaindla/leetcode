class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        int n=s.size();
        string ans="";
        ans+=s[0];
        for(int i=1;i<n;i++)
        {
             ans+=s[i];
             if(s[i]==s[i-1])
             {
                count++;
             }
             else
             {
                count=1;
             }
             if(count==3)
             {
                ans.pop_back();
                count--;
             }
        }
        return ans;
    }
};