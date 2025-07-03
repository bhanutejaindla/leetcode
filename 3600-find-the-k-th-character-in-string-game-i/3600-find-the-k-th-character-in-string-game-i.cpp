class Solution {
public:
    char kthCharacter(int k) {
        string str="a";
        while(true)
        {
           string s=str;
           for(int i=0;i<s.size();i++)
           {
            if(s[i]=='z') { s[i]='a'; continue; }
              s[i]=(s[i]+1);
           }
           str+=s;
           if(str.size()>=k) break;
        }
        return str[k-1];
    }
};