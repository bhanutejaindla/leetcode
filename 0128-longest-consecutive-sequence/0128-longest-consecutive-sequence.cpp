class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n=nums.size();
        set<int>s(nums.begin(),nums.end());
        vector<int>v(s.begin(),s.end());
        int left=0;
        int right=1;
        int cnt=1;
        int maxi=0;
        int n=v.size();
        if(n==0 || n==1) return n;
        while(right<n)
        {
             if(v[right]==v[right-1]+1)    right++;
             else 
             {
                maxi=max(maxi,right-left);
                left=right;
                right++;
             }
        }
        maxi=max(maxi,right-left);
        return  maxi;

    }
};