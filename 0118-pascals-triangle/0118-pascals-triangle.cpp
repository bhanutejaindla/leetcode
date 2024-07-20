class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>>ans;
         ans.push_back({1});
         if(numRows==1) return ans;
         for(int i=1;i<numRows;i++)
         {
            vector<int>v(i+1,1);
            for(int j=0;j<i+1;j++)
            {
                if(j!=0 && j!=i)
                v[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(v);
         }
         return ans;
    }
};