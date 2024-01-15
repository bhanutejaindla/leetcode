class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
          set<int>s;
          map<int,int>mp;
          // sort(matches.begin(),matches.end());
          for(int i=0;i<matches.size();i++)
          {
              s.insert(matches[i][1]);
              mp[matches[i][1]]++;
          }
          vector<vector<int>>v;
           vector<int>ans,ans1;
          for(int i=0;i<matches.size();i++)
          {
              if(s.find(matches[i][0])==s.end())
              {
                  ans.push_back(matches[i][0]);
                  s.insert(matches[i][0]);
              }
              if(mp[matches[i][1]]==1)
              {
                  ans1.push_back(matches[i][1]);
                  mp[matches[i][1]]++;
              }
          }
        sort(ans.begin(),ans.end());
        sort(ans1.begin(),ans1.end());
           return {ans,ans1};
        
        
    }
};