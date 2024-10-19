class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int cursum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            cursum+=nums[i];
            if(maxsum<=cursum)
            {
                maxsum=cursum;
            }
            if(cursum<0)
            {
                cursum=0;
            }

        }
        return maxsum;
    }
};