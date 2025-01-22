class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int cnt=0;
        int cnt1=n/2;
        int cnt2=n/2-1;
        int i=0,j=0,k=0;
        int ele1,ele2;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<=nums2[j])
            {
                if(cnt==cnt1) ele1=nums1[i];
                if(cnt==cnt2) ele2=nums1[i];
                cnt++;
                i++;
            }
            else
            {
               if(cnt==cnt1) ele1=nums2[j];
               if(cnt==cnt2) ele2=nums2[j];
               cnt++;
               j++;
            }
        }
        while(i<n1)
        {
            if(cnt==cnt1) ele1=nums1[i];
            if(cnt==cnt2) ele2=nums1[i];
            i++;
            cnt++;
        }
        while(j<n2)
        {
            if(cnt==cnt1) ele1=nums2[j];
            if(cnt==cnt2) ele2=nums2[j];
            j++;
            cnt++;
        }
        if(n%2==1)  return (double)ele1;
        else
        {
            return (double)(ele1+ele2)/2;
        }
    }
};