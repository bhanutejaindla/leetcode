class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int m=g.size();
        int n=s.size();
        int cnt=0;
        while(i<m && j<n)
        {
            if(s[i]>=g[j])
            {
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
        
    }
};