class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //1 2 2 3 3 4 6 7 8 
        //1 2 3
        //2 3 4
        //6 7 8      
        int n=hand.size();
        if(n%groupSize) return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int>mp;
        for(auto x:hand)
        {
            mp[x]++;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            int a=hand[i];
            if(mp[a]>0)
            {
            for(int j=0;j<groupSize;j++)
            {
                int v=hand[i]+j;
                if(mp.find(v)!=mp.end() && mp[v]>0)
                {
                     count++;
                     mp[v]--;
                }
                else return false;
            }
            }
            if(count==n) return true; 
        }
        return false;
        

    }
};