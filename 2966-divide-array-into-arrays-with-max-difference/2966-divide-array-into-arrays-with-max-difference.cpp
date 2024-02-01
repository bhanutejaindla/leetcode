class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        bool flag=true;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i=i+3)
        {
            if(abs(nums[i]-nums[i+1])>k)
            {
                flag=false;
                break;
            } 
            if(abs(nums[i+1]-nums[i+2])>k)
            {
                flag=false;
                break;
            }
            if(abs(nums[i]-nums[i+2])>k)
            {
                flag=false;
                break;
            }
            else
            {
               ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }
        }
         if(flag==true)  return ans;
         else return {};
    }
};