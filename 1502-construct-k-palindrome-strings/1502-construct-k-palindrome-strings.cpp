class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        int odd=0;
        for(auto x:mp)
        {
            if(x.second%2!=0) odd++;
        }
        return odd<=k;

 

    }
};