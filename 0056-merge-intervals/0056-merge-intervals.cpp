class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0];
        int e=intervals[0][1];
        vector<vector<int>>v;
        for(int i=1;i<n;i++)
        {
            if(e<intervals[i][0])
            {
              v.push_back({s,e});
              s=intervals[i][0];
              e=intervals[i][1];
            }
            else
            {
                e=intervals[i][1];
            }
        }
        v.push_back({s,e});
        return v;
    }
};