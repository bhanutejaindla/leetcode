class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        int tm=0;
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            int dx[4]={0,0,-1,1};
            int dy[4]={-1,1,0,0};
            for(int i=0;i<4;i++)
            {
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 && newy>=0 && newx<n && newy<m && vis[newx][newy]!=2 &&  grid[newx][newy]==1)
                {
                   q.push({{newx,newy},t+1});
                   vis[newx][newy]=2;
                   fresh--;
                }
            }
        }
        if(fresh!=0) return -1;
        else return tm;
    }
};