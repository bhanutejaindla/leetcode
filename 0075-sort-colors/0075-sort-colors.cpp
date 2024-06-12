class Solution {
public:
    void sortColors(vector<int>& arr) {
       int n=arr.size();
       int l=0;
       int r=n-1;
       for(int i=0;i<n && i<=r;)
       {
        if(arr[i]==0)
        {
            swap(arr[i],arr[l]);
            i++;
            l++;
        }
        else if(arr[i]==2)
        {
            swap(arr[i],arr[r]);
            r--;
        }
        else i++;
       }
       return ;
     
    }
};