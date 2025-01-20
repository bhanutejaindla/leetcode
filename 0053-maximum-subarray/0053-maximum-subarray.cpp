class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum=0;
        int maximumsum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            currentsum+=nums[i];
            if(currentsum>maximumsum)
            {
                maximumsum=currentsum;
            }
            if(currentsum<0)
            {
                currentsum=0;
            }
        }
        return maximumsum;
    }
};