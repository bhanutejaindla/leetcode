class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0];
        int e=intervals[0][1];
        int n=intervals.size();
         vector<vector<int>>ans;
         for(int i=1;i<n;i++)
         {
            if(e<intervals[i][0])
            {
                ans.push_back({s,e});
                s=intervals[i][0];
                e=intervals[i][1];
            }
            else
            {
                if(e>=intervals[i][0] && e>=intervals[i][1])
                {
                    continue;
                }
                else if(e>=intervals[i][0] && e<intervals[i][1])
                {
                     e=intervals[i][1];
                }
            }
         }
        ans.push_back({s,e});
         return ans;
    }
};