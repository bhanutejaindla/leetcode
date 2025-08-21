class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
               if(mat[i][j]==1) cnt++;
               else
               {
                  cnt=0;
               }
                mat[i][j]=cnt;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mini=INT_MAX;
                 for(int k=i;k<n;k++)
                 {
                      mini=min(mini,mat[k][j]);
                      ans+=mini;
                 }
            }
        }
        return ans;
    }
};