class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==ele)
            {
                cnt++;
            }
            if(nums[i]!=ele)
            {
                cnt--;
            }
            if(cnt<0)
            {
                ele=nums[i];
                cnt=1;
            }
        }
        if(cnt<0) return -1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(ele==nums[i]) count++;
        }
        if(count>(nums.size()/2)) return ele;
        else return -1;
    }
};