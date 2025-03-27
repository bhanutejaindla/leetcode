class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        vector<int>l(nums.size(),0);
        vector<int>r(nums.size(),0);
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            l[i]=mp[nums[i]];
        }
        cout<<endl;
        //l[0]=1;    r[n-4]=0
        //l[1]=1;    r[n-3]=2
        //l[2]=2;    r[n-2]=1
        //l[3]=3     r[n-1]=0
        r[n-1]=0;
        mp.clear();
        mp[nums[n-1]]++;
        for(int i=n-2;i>=0;i--)
        {
            r[i]=mp[nums[i]];
            mp[nums[i]]++;
        }
        int index=-1;
        for(int i=0;i<n;i++)
        {
           int a=l[i],b=r[i];
           if(a>(i+1)/2)
           {
            if(b>(n-i-1)/2) return i;
           }
        }
        return -1;
    }
};