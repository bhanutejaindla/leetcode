class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++) pq.push({nums[i],i});
        vector<int>ans;
        int j=0;
        ans.push_back(pq.top().first);
        for(int i=k;i<n;i++)
        {
        
            pq.push({nums[i],i});
            while(pq.top().second<=j)
            {
                pq.pop();
            }
            j++;
            ans.push_back(pq.top().first);
        }
        
         return ans;
    }
   
};