class Solution {
public:
    int countsetbits(int nums)
    {
        int x=nums;
        int cnt=0;
        while(x>0)
        {
           if(x&1) cnt++;
           x=x>>1;
        }
        return cnt;
    }
    int minimizeXor(int num1, int num2) {
      int bits2=countsetbits(num2);
      int bits1=countsetbits(num1);
      int res=num1;
      for(int i=0;i<32;i++)
      {
        if(bits1>bits2 && ((1<<i) & num1))
        {
           res^=1<<i;
           --bits1;
        }
        if(bits1<bits2 && !((1<<i) & num1))
        {
            res^=1<<i;
            ++bits1;
        }
      }
      return res;  
    }
};