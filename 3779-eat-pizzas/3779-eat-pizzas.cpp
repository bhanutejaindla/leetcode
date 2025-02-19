class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n=pizzas.size();
        int k=n/4;
        int odd=(k+1)/2;
        int even=k/2;
        priority_queue<int>pq(pizzas.begin(),pizzas.end());
        long long ans=0;
        while(!pq.empty() && odd>0)
        {
            ans+=pq.top();
            pq.pop();
            odd--;
        }
        while(!pq.empty() && even>0)
        {
            pq.pop();
            ans+=pq.top();
            pq.pop();
            even--;
        }
        return ans;
        
    }
};