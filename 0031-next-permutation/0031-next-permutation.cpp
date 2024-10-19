class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int indx=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                indx=i-1;
                break;
            }
        }
        if(indx==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>indx;i--)
        {
            if(nums[i]>nums[indx])
            {
              swap(nums[indx],nums[i]);
              break;
            }
        }
        reverse(nums.begin()+indx+1,nums.end());
        return ;


    }
};