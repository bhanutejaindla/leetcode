class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        int ans=0;
        while(j<n)
        {
           if(nums[j]%2) {
              count=0;
              k--;
           }
           while(k==0)
           {
               if(nums[i]%2)
               {
                 k++;
               }
               count++;
               i++;
           } 
         ans+=count;
         j++;
        }
        return ans;
    }
};