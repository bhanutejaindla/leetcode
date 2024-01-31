class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         int n=temperatures.size();
         stack<pair<int,int>>temp;
          vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            while(temp.size()>0 && temp.top().first<temperatures[i])
            {
                ans[temp.top().second]=i-temp.top().second;
                temp.pop();
            }
            temp.push({temperatures[i],i});  
        }
        return ans;
    }
};