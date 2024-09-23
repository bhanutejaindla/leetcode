class Solution {
public:
    int find(long a,long b,long n)
    {
        int ans=0;
        while(a<=n)
        {
          ans+=min(b,n+1)-a;
          a*=10;
          b*=10;
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
       long  curr=1;
       for(int i=1;i<k;)
       {
          int gap=find(curr,curr+1,n);
          if(i+gap<=k)
          {
             curr++;
             i+=gap;
          }
          else
          {
            i++;
            curr=curr*10;
          }
       }
       return curr;
    }
};