class Solution {
public:
   bool solve(vector<int>&num,int target,int k)
   {
        int cnt=0;
        for(int i=0;i<num.size()-1;i++)
        {
            if(num[i]!=target)
            {
                num[i]=-1*num[i];
                num[i+1]=-1*num[i+1];
                cnt++;
                if(cnt>k) return false;
            }
        }
        for(int i=0;i<num.size();i++){
            if(num[i]!=target) return false;
        }
        return true;
   }
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int>nums1=nums;
        return solve(nums,1,k) || solve(nums1,-1,k);
    }
};