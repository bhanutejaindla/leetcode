class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        int ans=0;
        for(int i=1;i<s.size();i++)
        {
            int a=s[i]-'0';
            int b=s[i-1]-'0';
             ans+=abs(a-b);   
        }
        return ans;
    }
};