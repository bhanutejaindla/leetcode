class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        priority_queue<pair<int,int>>pq;
        int n=x.size();
        for(int i=0;i<n;i++)
        {
            pq.push({y[i],x[i]});
        }
        unordered_set<int>s;
        int cnt=0,ans=0;
        while(!pq.empty() && cnt<3)
        {
            auto it =pq.top();
            pq.pop();
            if(s.find(it.second)==s.end())
            {
                ans+=it.first;
                s.insert(it.second);
                cnt++;
            }
        }
        if(cnt==3) return ans;
        else return -1;

    }
};