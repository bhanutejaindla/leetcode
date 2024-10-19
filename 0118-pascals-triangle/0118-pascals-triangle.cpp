class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>>ans;
        
         for(int i=0;i<numRows;i++)
         {
            if(i==0)  {ans.push_back({1}); continue; }
            vector<int>v;
            for(int j=0;j<i+1;j++)
            {
               if(j==0) v.push_back(1);
               else if(j==i) v.push_back(1);
               else 
               {
                  v.push_back(ans[i-1][j]+ans[i-1][j-1]);
               }
            }
            ans.push_back(v);
         }
         return ans;

    }
};