class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        set<string>st;
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            for(int j=0;j<n;j++)
            {
                string t=words[j];
                if(i!=j && t.size()>=s.size())
                {
                    int k=0;
                    for(int i=0;i<t.size() && k<s.size();i++)
                    {
                        if(s[k]!=t[i])
                        {
                            k=0;
                        }
                        int m=i;
                        int x=k;
                        int y=k;
                        while(m<t.size() && x<s.size() && s[x]==t[m])
                        {
                            m++;
                            x++;
                        }
                        if(x>=s.size())
                        {
                            k=s.size();
                            break;
                        }
                        k=y;
                    }
                    if(k==s.size()) st.insert(s);
                }
            }
        }
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};