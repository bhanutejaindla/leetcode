class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int num=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(num==nums[i]) cnt++;
            if(num!=nums[i]) cnt--;
            if(cnt<0)
            {
                cnt=0;
                num=nums[i];
            }
        }
        if(cnt>=0) return num;
        else return -1; 
    }
};