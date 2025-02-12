class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char>st;
        int n=s.size();
        string v="";
        int m=part.size();
        reverse(part.begin(),part.end());
        for(int i=0;i<n;i++)
        {
            st.push(s[i]);
            if(!st.empty() && st.size()>=m)
            {
               string ans="";
               int k=m;
               while(!st.empty() && k--)
               {
                ans+=st.top();
                st.pop();
               }
              if(ans==part) continue;
               for(int i=0;i<m;i++)
               {
                st.push(ans[m-i-1]);
               }
            }
        }
        string b;
        while(!st.empty())
        {
            b+=st.top();
            st.pop();
        }
        reverse(b.begin(),b.end());
        return b;
    }
};