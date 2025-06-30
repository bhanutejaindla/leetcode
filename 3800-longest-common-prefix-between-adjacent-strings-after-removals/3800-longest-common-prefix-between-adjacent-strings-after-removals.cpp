class Solution {
public:
    int solve(string word1,string word2)
    {
        int ans=0;
        for(int i=0;i<min(word1.size(),word2.size());i++)
        {
                if(word1[i]==word2[i])
                {
                    ans++;
                }
                else
                {
                    break;
                }
        }
        return ans;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
           int n=words.size();
           vector<int>lcp(n-1,0);
           vector<int>v;
           if(n<=1) return {0};
           for(int i=0;i+1<n;i++)
           {
              lcp[i]=solve(words[i],words[i+1]);
           }
           vector<int>prefmax(n-1),suffmax(n-1);
           prefmax[0]=lcp[0];
           for(int i=1;i<n-1;i++)
           {
              prefmax[i]=max(prefmax[i-1],lcp[i]);
           }
           suffmax[n-2]=lcp[n-2];
           for(int i=n-3;i>=0;i--)
           {
                 suffmax[i]=max(suffmax[i+1],lcp[i]);
           }
           for(int i=0;i<n;i++)
           {
              int b=0;
               if(i+1<=n-2)
               {
                 b=max(b,suffmax[i+1]);
               }
               if(i>=2)
               {
                b=max(b,prefmax[i-2]);
               }
               if(i>0 && i<n-1)
               {
                b=max(b,solve(words[i-1],words[i+1]));
               }
              v.push_back(b);
           }
             return v;
          
    
   


           
    }
};