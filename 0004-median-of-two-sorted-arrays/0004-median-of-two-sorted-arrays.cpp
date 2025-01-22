class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        vector<int>v(n);
        int i=0,j=0,k=0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<=nums2[j])
            {
                v[k++]=nums1[i++];
            }
            else
            {
                v[k++]=nums2[j++];
            }
        }
        while(i<n1 && k<n) v[k++]=nums1[i++];
        while(j<n2 && k<n) v[k++]=nums2[j++];
        if((n1+n2)%2==1)  return (double)v[(n1+n2)/2];
        else
        {
            return (double)(v[(n1+n2)/2 -1]+v[(n1+n2)/2])/2;
        }
    }
};