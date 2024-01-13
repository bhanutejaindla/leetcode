class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(mp[t[i]]>0)  mp[t[i]]--;
        }
        int sum=0;
        for(auto x:mp)
        {
            sum+=x.second;
        }
        return sum;
    }
};