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
        int i=0;
        int j=n-1;
        long long ans=0;
        sort(skill.begin(),skill.end());
        while(i<=j)
        {
            if(skill[i]+skill[j]==sumeach)
            {
              ans+=(skill[i]*skill[j]);
              i++;
              j--;
            }
            else return -1;
        }
        return ans;
    }
};