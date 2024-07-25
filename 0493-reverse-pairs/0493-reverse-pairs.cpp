class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high)
    {
         int size1=mid-low+1;
         int size2=high-mid;
         int left[size1];
         int right[size2];
         for(int i=0;i<size1;i++)
         {
            left[i]=nums[i+low];
         }
         for(int i=0;i<size2;i++)
         {
            right[i]=nums[mid+1+i];
         }
         int i=0;
         int j=0;
         int k=low;
         int pairs=0;
         for (i = 0, j = 0; i < size1; i++) {
            while (j < size2 && left[i] > 2LL * right[j]) {
                j++;
            }
            pairs += j;
        }
        i=0;j=0;k=low;
         while(i<size1 && j<size2)
         {
            if(left[i]<=right[j])
            {
                nums[k++]=left[i++];
            }
           else if(left[i]>right[j])
            {
                nums[k++]=right[j++];
            }
         }
         while(i<size1)
         {
            nums[k++]=left[i++];
         }
         while(j<size2)
         {
            nums[k++]=right[j++];
         }
         return pairs;
    }
    int mergesort(vector<int>&nums,int low,int high)
    {
        if(low>=high) return 0;
        int count=0;
        int mid=low+(high-low)/2;
        count+=mergesort(nums,low,mid);
        count+=mergesort(nums,mid+1,high);
        count+=merge(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
       return mergesort(nums,0,n-1);
    }
};