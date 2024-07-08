class Solution {
public:
    int findTheWinner(int n, int k) {
         queue<int>q;
        for(int i=1;i<=n;i++) q.push(i);
        while(!q.empty())
        {
            int m=k-1;
            if(q.size()==1)  break;
            while(m--)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};