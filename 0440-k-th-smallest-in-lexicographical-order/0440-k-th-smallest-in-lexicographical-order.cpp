class Solution {
public:
    int find(long a,long b,long n)
    {
        int ans=0;
        while(a<=n)
        {
            ans+=min(b,n+1)-a;
            a=a*10;
            b=b*10;
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        for(int i=1;i<k;)
        {
            int gap=find(curr,curr+1,n);
            if(i+gap<=k)
            {
                i+=gap;
                curr++;
            }
            else
            {
                curr=curr*10;
                i++;
            }
        }
        return curr;
    }
};