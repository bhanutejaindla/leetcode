class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int mindx=m-1;
       int nindx=n-1;
       int right=m+n-1;
       while(nindx>=0)
       {
         if(mindx>=0 && nums1[mindx]>nums2[nindx])
         {
            nums1[right]=nums1[mindx];
            right--;
            mindx--;
         }
         else
         {
            nums1[right]=nums2[nindx];
            right--;
            nindx--;
         }
       }
       return ;

    }
};