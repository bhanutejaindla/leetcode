class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
           int n=value.size();
           map<int,vector<int>>mp;
           for(int i=0;i<n;i++)
           {
              mp[limit[i]].push_back(value[i]);
           }
           long long ans=0;
           for(auto &x:mp)
           {
              int a=x.first;
              auto v=x.second;
              sort(v.begin(),v.end(),greater<int>());
              int len=min(a,(int)v.size());
              for(int i=0;i<len;i++) ans+=v[i];
           }
           return ans;

    }
};