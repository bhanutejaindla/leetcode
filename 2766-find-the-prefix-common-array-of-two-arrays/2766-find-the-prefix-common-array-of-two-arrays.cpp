class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp,mp1;
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            mp[A[i]]++;
            mp1[B[i]]++;
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(mp.find(j)!=mp.end() && mp1.find(j)!=mp1.end())
                {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};