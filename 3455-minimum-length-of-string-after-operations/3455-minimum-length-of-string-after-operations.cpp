class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]==3)
            {
                mp[s[i]]=1;
            }
        }
        int cnt=0;
        for(auto x:mp)
        {
            cnt+=x.second;
        }
        return cnt;
    }
};