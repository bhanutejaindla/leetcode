class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char,int>mp;
       for(auto x:s)
       {
          mp[x]++;
       } 
       int cnt=0;
       int ones=0;
      for(auto x:mp)
       {
           if(x.second%2==0)
           {
             cnt+=x.second;
           }
           else if(x.second%2==1)
           {
               cnt+=(x.second/2)*2;
                ones++;
           }
       }
       if(ones>0)  cnt++;
       return cnt;
    }
};