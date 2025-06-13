class Solution {
    public int minimizeMax(int[] nums, int p) {
        if(p==0) return 0;
         
         Arrays.sort(nums);
         int n=nums.length;
         int l=0;
         int r=nums[n-1]-nums[0];
         while(l<r)
         {
            int mid=l+(r-l)/2;
            int pairs=0;
            for(int i=1;i<n;i++)
            {
                if((nums[i]-nums[i-1])<=mid)
                {
                    pairs++;
                    i++;
                }
            }
            if(pairs>=p)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
         }
         return l;
    }
}