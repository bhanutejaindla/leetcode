class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        int size=original.size();
        if(m*n>size) return {};
        int k=0;
        for(int i=0;i<m && k<size;i++)
        {
            vector<int>v;
            for(int j=0;j<n;j++)
            {
             v.push_back(original[k]);
             k++;
            }
            ans.push_back(v);
        }
        if(k<size) return {};
        return ans;
    }
};