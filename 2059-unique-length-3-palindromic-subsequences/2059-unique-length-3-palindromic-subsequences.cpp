class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
             mp[s[i]]=i;
        }
        // int pref[n];
        // pref[0]=0;
        unordered_set<int>st;
        // st.insert(s[0]);
        // for(int i=1;i<n;i++)
        // {
        //    pref[i]=st.size();
        //    st.insert(s[i]);
        // }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<pref[i]<<" ";
        // }
        // cout<<endl;
        //  st.clear();
         int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                if(mp[s[i]]-i>=2 && st.find(s[i])==st.end())
                {
                    int left=i;
                    int right=mp[s[i]];
                    string str=s.substr(left+1,right-left-1);
                    cout<<str<<endl;
                    unordered_set<char>mp1(str.begin(),str.end());
                    ans+=mp1.size();
                    st.insert(s[i]);
                }  
            }
        }
        return ans;
    }
};