class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int n=nums.size();
        int maj=0;
        for(int i=0;i<n;i++)
        {
          if(nums[maj]==nums[i])
          {
              count++;
          }
          else
          {
              count--;
          }
          if(count==0) 
          {
              count=1;
              maj=i;
          }
        }
        return nums[maj];

    }
};