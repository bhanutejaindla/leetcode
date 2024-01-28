class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        unordered_map<int,int>mp;
        int res=0;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        // unordered_map<int,int>mp;
        int ans=0;
        for(int colstart=0;colstart<n;colstart++)
        {
            for(int colend=colstart;colend<n;colend++)
            {
                int cursum=0;
                mp={{0,1}};
                for(int row=0;row<m;row++)
                {
                    cursum+=matrix[row][colend]-(colstart?matrix[row][colstart-1]:0);
                    ans+=mp[cursum-target];
                    mp[cursum]++;
                }
            }
        }
        return ans;
    }
};