class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            int mini=INT_MAX;
            int maxi=0;
            int col=0;
            for(int j=0;j<n;j++)
            {
               if(mini>matrix[i][j])
               {
                  mini=matrix[i][j];
                  col=j;
               }
            }
            for(int row=0;row<m;row++)
            {
               maxi=max(maxi,matrix[row][col]);
            }
            if(mini==maxi)  ans.push_back(mini);
        }
        return ans;
    }
};