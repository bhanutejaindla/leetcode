class Solution {
public:
    double myPow(double x, int n) {
        bool flag=true;
        if(n<0)
        {
          flag=false;
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
        if(!flag)
        {
            return 1.0/ans;
        }
        else return ans;
    }
};