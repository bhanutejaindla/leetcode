class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(m<n)  return "";
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)  mp[t[i]]++;
        int count=n;
        int i=0;
        int j=0;
        int minlen=INT_MAX;
        int start=0;
        while(j<m)
        {
            if(mp[s[j]]>0)
            {
                count--;
               
            }
             mp[s[j]]--;
            j++;
            while(count==0)
            {
                 if(minlen>j-i)
                 {
                     start=i;
                     minlen=j-i;
                 }
                 mp[s[i]]++;
                 if(mp[s[i]]>0)
                 {
                     count++;
                 }
                 i++;
            }
            
        }
        if(minlen!=INT_MAX) return s.substr(start,minlen);
        else return "";
        
        
    }
};