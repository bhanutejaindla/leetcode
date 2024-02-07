class Solution {
public:
    bool static comp(pair<int,char>&p1,pair<int,char>&p2)
    {
        if(p1.first==p2.first)  return  p1.second>p2.second;
        return  p1.first>p2.first;
    }
    string frequencySort(string s) {
         unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto x:mp)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),comp);
        string ans="";
        for(int i=0;i<v.size();i++)
        {
           int a=v[i].first;
           while(a--)
           {
               ans+=v[i].second;
           }
        }
       
        return ans;
    }
};