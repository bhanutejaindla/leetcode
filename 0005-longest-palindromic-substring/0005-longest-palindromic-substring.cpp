class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int first=0;
        int last=0;
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            int low=i-1;
            int high=i;  //odd substring
            while(low>=0 && high<n && s[low]==s[high])
            {
             if(maxi<high-low+1) {  
                    first=low;
                    last=high;
                    maxi=high-low+1;
             }  
                low--;
               high++;
            }
             low=i-1;
             high=i+1;
            while(low>=0 && high<n && s[low]==s[high])
            {
                if(maxi<=high-low+1)
                {
                   first=low;
                    last=high;
                    maxi=high-low+1;  
                }
                low--;
                    high++; 
            }
        }
        
        return s.substr(first,maxi);
    }
};