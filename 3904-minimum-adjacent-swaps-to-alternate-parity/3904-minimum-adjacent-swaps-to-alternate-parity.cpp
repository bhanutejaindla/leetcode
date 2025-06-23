class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>even,odd;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
              even.push_back(i);
            }
            else odd.push_back(i);
        }
        int el=even.size();
        int ol=odd.size();
        int ans=INT_MAX;
        if(abs(el-ol)>1) return -1;
        if(el>=ol)
        {
            int x=0;
           for(int i=0;i<even.size();i++)
           {
             x+=abs(2*i-even[i]);
           }
           ans=min(ans,x);           
        }
        if(ol>=el)
        {
            int x=0;
           for(int i=0;i<odd.size();i++)
           {
             x+=abs(2*i-odd[i]);
           }
           ans=min(ans,x);       
        }
        return ans;
        
        
    }
};