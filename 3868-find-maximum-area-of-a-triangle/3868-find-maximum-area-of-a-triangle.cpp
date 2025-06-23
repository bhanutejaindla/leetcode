class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int n=coords.size();
        map<int,pair<int,int>>mp;
        int maxix=0;
        int minix=INT_MAX;
        for(auto x:coords)
        {
            if(mp.find(x[0])==mp.end())
            {
               mp[x[0]]={x[1],x[1]};
            }
            else
            {
                int mini=min(mp[x[0]].first,x[1]);
                int maxi=max(mp[x[0]].second,x[1]);
                mp[x[0]]={mini,maxi};
            }
            maxix=max(maxix,x[0]);
            minix=min(minix,x[0]);
        }
        long long maxarea=0;
        for(auto x:mp)
        {
              int a=x.second.first;
              int b=x.second.second;
              int c=x.first;
              if(a!=b )
              {
                 long long  diff=max(abs(c-maxix),abs(c-minix));
                long long  area=diff*abs(a-b) ;
                 maxarea=max(maxarea,area);
              }
        }
        cout<<maxarea<<endl;
        int maxiy=0;
        int miniy=INT_MAX;
        unordered_map<int,pair<int,int>>mp1;
        for(auto x:coords)
        {
            if(mp1.find(x[1])==mp1.end())
            {
               mp1[x[1]]={x[0],x[0]};
            }
            else
            {
                int mini=min(mp1[x[1]].first,x[0]);
                int maxi=max(mp1[x[1]].second,x[0]);
                mp1[x[1]]={mini,maxi};
            }
            maxiy=max(maxiy,x[1]);
            miniy=min(miniy,x[1]);
        }
        cout<<miniy<<" "<<maxiy<<endl;
        for(auto x:mp1)
        {
              int a=x.second.first;
              int b=x.second.second;
              int c=x.first;
              cout<<a<<" "<<b<<endl;
              if(a!=b )
              {
                 long long diff=max(abs(c-maxiy),abs(c-miniy));
                 long long area=diff*abs(a-b) ;
                 cout<<area<<endl;
                 maxarea=max(maxarea,area);
              }
        }
        if(maxarea==0) return -1;
        return maxarea;
        

    }
};