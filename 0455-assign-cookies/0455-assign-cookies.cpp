class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int i=0,j=0;
        int n=g.size();
        int m=s.size();
        while(i<n && j<m)
        {
            if(g[i]<=s[j])
            {
                cnt++;
                j++;
                i++;
            }
            else j++;
        }
        return cnt;
    }
};