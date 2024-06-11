class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size();
        int n=arr2.size();
        vector<int>ans;
        unordered_set<int>s(arr2.begin(),arr2.end());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr2[i]==arr1[j]) ans.push_back(arr1[j]);
            }
        }
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<m;i++)
        {
            if(s.find(arr1[i])==s.end())
            {
                    ans.push_back(arr1[i]);
            }
        }
        return ans;
        
    }
};