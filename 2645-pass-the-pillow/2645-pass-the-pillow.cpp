class Solution {
public:
    int passThePillow(int n, int time) {
        int i=1;
        int t=0;
        bool flag=true;
        while(true)
        {
            if(flag==true)
            {
                i++;
                if(i==n)  flag=false;
            }
            else if(flag==false)
            {
                i--;
                if(i==1) flag=true;
            }
            t++;
            if(t==time)
            {
                return i;
            }
        }
        return -1;

    }
};