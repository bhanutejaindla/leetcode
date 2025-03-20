class Solution {
public:
   int mod=1e9+7;
    long long int calculatepower(long long x,long long n)
    {
        int num=1;
        while(n>0)
        {
            if(n%2==0)
            {
                x=(x*x)%mod;
                n=n/2;
            }
            else
            {
                num=(num*x)%mod;
                n=n-1;
            }
        }
        return num%mod;
    }
    int countGoodNumbers(long long n) {
        long long int ans=calculatepower(20,n/2)%mod;
        return n%2==0?ans%mod:(ans*5)%mod;

    }
};