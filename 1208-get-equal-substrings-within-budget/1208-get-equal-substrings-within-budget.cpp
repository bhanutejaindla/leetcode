class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>v;
        for(int i=0;i<s.size();i++)
        {
            v.push_back(abs(s[i]-t[i]));
        }
        int left=0;
        int right=0;
        int n=v.size();
        int sum=0;
        int maxilen=0;
        while(right<n)
        {
           sum+=v[right];
           while(sum>maxCost)
           {
              sum-=v[left];
              left++;
           }
           if(sum<=maxCost)
           {
            maxilen=max(maxilen,right-left+1);
           }
           right++;
        }
        return maxilen;
    }
};