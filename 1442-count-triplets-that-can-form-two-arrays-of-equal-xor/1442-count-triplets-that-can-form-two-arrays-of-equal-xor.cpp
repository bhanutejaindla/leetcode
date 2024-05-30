class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        bool flag=true;
        for(int x=0;x<n;x++){
            int a=0;
        for(int i=x;i<n;i++)
        {
            a=a^arr[i];
            int b=0;
            for(int j=i+1;j<n;j++)
            {
                b=b^arr[j];
                if(a==b)   count++;
            }
        }
        }
        return count;
    }
};