class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //1 2 2 4
        //1 2 3 4
        //c-d=-1
        //(c-d)(c+d)=-5
        //c+d=5
       long long int sum=0;
        long long int sum1=0;
        long long int n=nums.size();
        sum1=accumulate(nums.begin(),nums.end(),0);
        sum=(n*(n+1))/2;
        long long int aminusb=sum1-sum;
        long long int sqrsum=(n*(n+1)*(2*n+1))/6;
        long long int sqrsum1=0;
        for(auto x:nums)
        {
            sqrsum1+=x*x;
        }
       long long  int sqra_b=sqrsum1-sqrsum;
       long long  int ans=(sqra_b)/(aminusb);
       long long  int a=(ans+aminusb)/2;
       long long  int b=(ans-aminusb)/2;
        return {(int)a,(int)b};

    }
};