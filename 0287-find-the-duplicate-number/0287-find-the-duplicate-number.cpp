class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int fast=nums[i];
        int slow=nums[i];
        int n=nums.size();
        while(1)
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(fast==slow) 
            {
                break;
            }
        }
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};