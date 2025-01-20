class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        vector<int>prev;
        for(int i=0;i<numRows;i++)
        {
            vector<int>ans(i+1,-1);
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    ans[j]=1;
                }
                if(j==i)
                {
                    ans[j]=1;
                }
                else if(j>0 && j<i)
                {
                    ans[j]=prev[j-1]+prev[j];
                }
                cout<<ans[j]<<" ";
            }
              v.push_back(ans);
            prev=ans;
        }
        return v;
    }
};