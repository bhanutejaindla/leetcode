class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>r,c;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                 if(matrix[i][j]==0)
                 {
                    r.insert(i);
                    c.insert(j);
                 }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            if(r.find(i)!=r.end())
            {
              for(int j=0;j<matrix[0].size();j++)
              {
                matrix[i][j]=0;
              }
            }
        }
         for(int j=0;j<matrix[0].size();j++)
        {
            if(c.find(j)!=c.end())
            {
              for(int i=0;i<matrix.size();i++)
              {
                  matrix[i][j]=0;
              }
            }
        }
        return ;
    }
};