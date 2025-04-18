class Solution {
public:
    int  helper(vector<int>&nums)
    {
        int n=nums.size();
         vector<int>leftsmaller;
         stack<int>st;
         for(int i=0;i<n;i++)
         {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.empty()) leftsmaller.push_back(0);
            else leftsmaller.push_back(st.top()+1);
            st.push(i);
         }
         vector<int>rightsmaller;
         while(!st.empty()) st.pop();
         for(int i=n-1;i>=0;i--)
         {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.empty()) rightsmaller.push_back(n-1);
            else rightsmaller.push_back(st.top()-1);
            st.push(i);
         }
         int maxi=0;
         reverse(rightsmaller.begin(),rightsmaller.end());
         for(int i=0;i<n;i++)
         {
            maxi=max(maxi,(rightsmaller[i]-leftsmaller[i]+1)*nums[i]);
          
         }
         return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int cols=matrix[0].size();
        vector<int>dp(cols,0);
        int maxi=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                dp[j]+=(matrix[i][j]-'0');
                else 
                dp[j]=0;
            }
            maxi=max(maxi,helper(dp));
        }
        return maxi;
    }
};