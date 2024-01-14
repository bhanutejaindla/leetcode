class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if(m!=n)  return false;
        unordered_map<int,int>mp,mp1;
        unordered_set<char>s,s1;
        for(int i=0;i<m;i++)
        {
            mp[word1[i]]++;
            s.insert(word1[i]);
        }
        for(int i=0;i<m;i++)
        {
            mp1[word2[i]]++;
            s1.insert(word2[i]);
        }
        vector<int>v1,v2;
        for(auto x:mp)
        {
            v1.push_back(x.second);
        }
        if(s!=s1)  return false;
        for(auto x:mp1)
        {
           v2.push_back(x.second);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};