class Solution {
public:
    double myPow(double x, int n) {
        bool flag=false;
        if(n<0)
        {
           flag=true;
           n=abs(n);
        }
        double ans=1;
        while(n>0)
        {
              if(n%2==0)
              {
                x=x*x;
                n=n/2;
              }
              else 
              {
                  ans=ans*x;
                  n=n-1;
              }
        }
        if(flag==true)
        {
           return 1/ans;
        }
        else return ans;
    }
};