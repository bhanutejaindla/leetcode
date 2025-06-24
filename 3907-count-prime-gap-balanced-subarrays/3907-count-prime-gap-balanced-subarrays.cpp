class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<bool>prime(maxi+1,true);
        for(int i=2;i*i<=maxi;i++)
        {
            for(int p=i*i;p<=maxi;p+=i)
            {
                if(prime[p]==true)
                {
                    prime[p]=false;
                }
            }
        }
        prime[0]=false;
        prime[1]=false;

        multiset<int>s;
        int l=0,r=0,ans=0;
        int prev=-1,curr=-1;
        while(r<n)
        {
               if(prime[nums[r]]==true)
               { 
                    prev=curr;
                    curr=r;
                    s.insert(nums[r]);
               }
               while(s.size() && (*s.rbegin()-*s.begin())>k)
               {
                  if(prime[nums[l]]==true)
                  {
                    s.erase(s.find(nums[l]));
                  }
                  l++;
               }
               if(s.size()>=2)
               {
                  ans+=(prev-l+1);
               }
               r++;
        }
        return ans;
    }
};