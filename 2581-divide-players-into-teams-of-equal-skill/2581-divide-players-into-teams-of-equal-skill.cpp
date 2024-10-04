class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        if(n%2!=0) return -1;
        long long sum=0;
        for(auto x:skill)
        {
            sum+=x;
        }
        int teams=n/2;
        if(sum%teams!=0) return -1;
        int sumeach=sum/teams;
        unordered_map<int,int>mp;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(sumeach-skill[i])!=mp.end() && mp[sumeach-skill[i]]>0 )
            {
                
                    ans+=skill[i]* (sumeach-skill[i]);
                    mp[sumeach-skill[i]]--;
    
            }
            else
            {
                mp[skill[i]]++;
            }
        }
        for(auto x:mp)
        {
            if(x.second!=0) return -1;
        }
        if(ans==0) return -1;
        return ans;
    }
};