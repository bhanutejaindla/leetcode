class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int ones =1;
        int cntones = 0;
        if(nums[0] == 1) cntones++;
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] == 1) cntones++;
            if(nums[i] == 1 && nums[i-1] == 1)
            {
               ones ++;   
            }
            else
            {
                maxi = max(maxi,ones);
                ones = 1;
            }
        }
        maxi = max(maxi,ones);
        if(cntones == 0) return 0;
        return maxi;
        

    }
};