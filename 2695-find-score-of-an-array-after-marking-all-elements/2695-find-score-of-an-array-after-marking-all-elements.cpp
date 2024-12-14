class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    unordered_map<int,bool>mp;
    for(int i=0;i<nums.size();i++)
    {
        pq.push({nums[i],i});
        mp[i]=false;
    }
    long long ans=0;
    while(!pq.empty())
    {
        int a=pq.top().second;
        if(mp.find(a)!=mp.end()){
        ans+=nums[a];
        cout<<nums[a]<<endl;
        mp.erase(a);
        if(a>=1) mp.erase(a-1);
        if(a<=n-2) mp.erase(a+1);
        }
        pq.pop();
        
        if(mp.empty()) break; 
    }
    return ans;
    }
};