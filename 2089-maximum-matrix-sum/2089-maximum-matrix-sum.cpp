class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int negcount=0;
        int minimum=INT_MAX;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<0)
                {
                    negcount++;
                }
                minimum=min(minimum,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        if(negcount%2==0) return sum;
        else return sum-2*minimum;

    }
};