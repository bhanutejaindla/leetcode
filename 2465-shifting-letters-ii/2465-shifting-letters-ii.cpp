class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size();
        int m=s.size();
        // for(int i=0;i<n;i++)
        // {
        //      int start=shifts[i][0];
        //      int end=shifts[i][1];
          
        //         for(int j=start;j<=end;j++)
        //         {
        //             if(shifts[i][2]==0)
        //             {
        //               if(s[j]!='a')
        //             {
        //                 s[j]=s[j]-1;
        //             }
        //             else
        //             {
        //                 s[j]='z';
        //             }
        //             }
        //             if(shifts[i][2]==1)
        //             {
        //                 if(s[j]!='z')
        //             {
        //                 s[j]=s[j]+1;
        //             }
        //             else
        //             {
        //                 s[j]='a';
        //             }
        //             }
        //         }
            
        // }
        vector<int>v(m+1,0);
        sort(shifts.begin(),shifts.end());
        // int start=shifts[i][0];
        // int end=shifts[i][1];
        // for(int i=1;i<n;i++)
        // {
        //    if(shifts[i][0]>end)
        //    {
        //      for(int j=start;j<=end;j++)
        //      {
        //         if(shifts[i][2]==1)
        //         {
        //             if(s[i]!='z') s[i]=s[i]+1;
        //             else s[i]='a';
        //         }
        //         if(shifts[i][2]==0)
        //         {
        //             if(s[i]!='a') s[i]=s[i]-1;
        //             else s[i]='z';
        //         }
        //         end=shifts[i][1];
        //         start=shifts[i][0];
        //      }
        //    }
           
        // }
         for(int i=0;i<m;i++)
         {
            v[i]=s[i]-'a';
         }
         vector<int>v1(m+1,0);
         v1[0]=v[0];
         for(int i=1;i<m;i++)
         {
            v1[i]=v[i]-v[i-1];
         }
         for(int i=0;i<n;i++)
         {
            int s=shifts[i][0];
            int e=shifts[i][1]; 
            if(shifts[i][2]==0)
            {
                v1[s]-=1;
                v1[e+1]+=1;
            }
            else
            {
                v1[s]+=1;
                v1[e+1]-=1;
            }
         }
         for(int i=1;i<m;i++)
         {
             v1[i]+=v1[i-1];
         }
         cout<<endl;
         string str="";
         for(int i=0;i<m;i++)
         {
            v1[i]=(v1[i]%26);
            if(v1[i]<0)  v1[i]=26+v1[i];
            cout<<v1[i]<<endl;
            char ch='a'+v1[i];
            str+=ch;
         }
        return str;
    }
};