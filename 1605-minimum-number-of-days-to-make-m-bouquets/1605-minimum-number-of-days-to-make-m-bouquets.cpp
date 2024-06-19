class Solution {
public:
    bool bloom(vector<int>&bloomDay,int m,int k,int mid)
    {
        int count=0;
        int bouquets=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)
            {
               count++;
               if(count==k)
               {
                bouquets++;
                count=0;
               }
            }
            else
            {
                count=0;
            }
            if(bouquets>=m) return true;
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long v=(long long)m*k;
        int n=bloomDay.size();
        if(v>n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(bloom(bloomDay,m,k,mid))
            {    ans=mid; high=mid-1; }
            else low=mid+1;
        }
        return ans;
    }
};