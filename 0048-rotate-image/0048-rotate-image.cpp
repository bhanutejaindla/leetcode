class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
               int k=matrix[i][j];
               matrix[i][j]=matrix[j][i];
               matrix[j][i]=k;
            }
        }
        int left=0,right=n-1;
        while(left<right)
        {
            for(int i=0;i<matrix.size();i++)
            {
                 swap(matrix[i][left],matrix[i][right]);
            }
            left++;
            right--;
        }
        return ;

    }
};