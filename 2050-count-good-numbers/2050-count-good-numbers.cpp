class Solution {
public:
   int mod=1e9+7;
   int calpow(long long x,long long n)
   {
    long long ans=1;
    while(n>0)
    {
        if(n%2==0)
        {
            x=(x*x)%mod;
            n=n/2;
        }
        else
        {
            ans=(ans*x)%mod;
            n=n-1;
        }
    }
    return ans;
   }
    int countGoodNumbers(long long n) {
        long long ans=(calpow(20,n/2))%mod;
        if(n%2==0)
        {
            return ans;
        }
        else
        {
            return (ans*5)%mod;
        }
    }
};