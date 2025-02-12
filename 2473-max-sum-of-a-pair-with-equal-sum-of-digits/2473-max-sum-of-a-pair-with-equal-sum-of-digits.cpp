class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
           int num=nums[i];
           int sum=0;
           while(num>0)
           {
            sum+=num%10;
            num/=10;
           } 
           mp[sum].push(nums[i]);
        }
        int maxi=INT_MIN;
        for(auto x:mp)
        {
          priority_queue<int>pq=x.second;
          if(pq.size()<2) continue;
           int a=pq.top();
           pq.pop();
           int b=pq.top();
           pq.pop();
           maxi=max(maxi,a+b);
        }
        return maxi!=INT_MIN?maxi:-1;
    }
};