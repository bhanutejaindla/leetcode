class Solution {
public:
    bool isStartwithvowel(string &str)
    {
        int s=0;
        int e=str.size()-1;
        if((str[s]=='a' || str[s]=='e' || str[s]=='i' || str[s]=='o' || str[s]=='u') &&  (str[e]=='a' || str[e]=='e' || str[e]=='i' || str[e]=='o' || str[e]=='u'))
        return true; 
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
         int m=words.size();
         vector<int>v(m,0);
         cout<<m<<endl;
         for(int i=0;i<m;i++)
         {
            if(isStartwithvowel(words[i]))
            {
                // cout<<i<<endl;
                if(i==0) v[i]=1;
                else v[i]=v[i-1]+1;
            }
            else
            {
                if(i>0) v[i]=v[i-1];
                if(i==0) v[i]=0;
            }
            
            // cout<<v[i]<<endl;
         }
         for(int i=0;i<v.size();i++)
         {
            cout<<v[i]<<" ";
         }
         cout<<endl;
         vector<int>ans;
       for(int i=0;i<queries.size();i++)
       {
        int x=queries[i][0];
        int y=queries[i][1];
        if(x==0) ans.push_back(v[y]);
        else ans.push_back(v[y]-v[x-1]);
       }
        return ans;
    }
};