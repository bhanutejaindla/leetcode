class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                bool isvalid1=(j-i>=i) && equal(nums.begin(),nums.begin()+i,nums.begin()+i);
                bool isvalid2=(n-j>=j-i) && equal(nums.begin()+i,nums.begin()+j,nums.begin()+j);
                if(isvalid1 || isvalid2) count++;
            }
        }
        return count;
    }
};