class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        int m=s1.size();
        map<char,int>mp;
        for(auto x:s1)
        {
            mp[x]++;
        }
        for(int i=0;i<=n-m;i++)
        {
            map<char,int>mp1;
            for(int j=i;j<i+m;j++)
            {
                mp1[s2[j]]++;
            }
            if(mp==mp1) return true;
        }
        return false;
    }
};