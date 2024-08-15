class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivedollar=0;
        int tendollar=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                fivedollar++;
            }
            else if(bills[i]==10)
            {
                if(fivedollar>0)
                {
                    fivedollar--;
                    tendollar++;
                }
                else return false;
            }
            else
            {
                if(fivedollar>0 && tendollar>0)
                {
                    fivedollar--;
                    tendollar--;
                }
                else if(fivedollar>2)
                {
                    fivedollar-=3;
                }
                else return false;
            }
        }
        return true;
    }
};