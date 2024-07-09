class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time=customers[0][1];
        double waitingtime=customers[0][0]+customers[0][1];
        for(int i=1;i<customers.size();i++)
        {
            if(customers[i][0]>waitingtime)
            {
                time+=customers[i][1];
                waitingtime=customers[i][0]+customers[i][1];
            }
            else
            {
                waitingtime+=customers[i][1];
                time+=waitingtime-customers[i][0];
            }
        }
        double n=customers.size();
        return time*1.00000/n ;
    }
};