class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
          int u=edges[i][0];
          int v=edges[i][1];
          int s=edges[i][2];
          int e=edges[i][3];
          adj[u].push_back({v,s,e});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0});
        vector<int>time(n,INT_MAX);
        int t=0;
        while(!pq.empty())
        {
            int t=pq.top()[0];
            int u=pq.top()[1];
            pq.pop();
            if(t>=time[u]) continue;
             time[u]=t;
            for(auto x:adj[u])
            {
                 int v=x[0];
                 int start=x[1];
                 int end=x[2];
                 int temp=t;
                 if(temp>end) continue;
                 if(temp<start) temp=start;
                 temp+=1;
                 if(temp<time[v])
                 {
                    pq.push({temp,v});
                 }

            }
        }
       return time[n-1]!=INT_MAX?time[n-1]:-1;
    }
};