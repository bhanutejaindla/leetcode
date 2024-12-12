class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        long long ans=0;
        priority_queue<int>pq(gifts.begin(),gifts.end());
        while(k--)
        {
            int a=pq.top();
            pq.pop();
            pq.push(sqrt(a));
        }
        while(n--)
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};