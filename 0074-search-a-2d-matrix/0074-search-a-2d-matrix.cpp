class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            int lo=0;
            int hi=n-1;
            while(lo<=hi)
            {
                int mi=lo+(hi-lo)/2;
                if(matrix[i][mi]==target)
                {
                    return true;
                }
                else if(matrix[i][mi]>target)
                {
                    hi=mi-1;
                }
                else
                {
                    lo=mi+1;
                }
            }
        }
        return false;
    }
};