class Solution {
public:
    int countoccurences(string &s,const string &x)
    {
        int count=0;
        int m=s.size();
        int n=x.size();
       
        int cnt=0;
        int i=0;
        int j=0;
        while(i<m)
        {
            if(s[i]==x[j])
            {
              j++;
              if(j==n)

              {
                j=0;
                cnt++;
              }  

            }
            i++;
        }
        return cnt;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
         int n=s.size();
         vector<int>freq(26,0);
         for(int i=0;i<s.size();i++) freq[s[i]-'a']++;
         queue<string>q;
         string curr="";
         q.push(curr);
         string res="";
         while(!q.empty())
         {
            curr=q.front();
            q.pop();
            string next=curr;
            for(char ch='a';ch<='z';ch++)
            {
                if(freq[ch-'a']<k) continue;
                next.push_back(ch);
                if(countoccurences(s,next)>=k)
                {
                    res=next;
                    q.push(res);
                }
                next.pop_back();
            }
         }
         return res;
    }
};