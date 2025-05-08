class Solution {
public:
    double myPow(double x, int n) {
        bool neg=0;
        if(x==1 || x==0) return x;
        long long  m=(long long)n;
        if(m<0) {neg=1; m=abs(m);}
        double ans=1;
        while(m>0)
        {
            if(m%2==0)
            {
                x=x*x;
                m=m/2;
            }
            else
            {
                ans=ans*x;
                m=m-1;
            }
        }
        if(neg==1) return (double)1/ans;
        return ans;
    }
};