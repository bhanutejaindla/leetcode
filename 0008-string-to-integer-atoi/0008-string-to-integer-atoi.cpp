class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(s[i]==' ')
        {
            i++;
        }
        cout<<i<<endl;
        bool add=true;
        int cnt=0;
        while(s[i]=='-') { add=false; i++; cnt++;}
        while(s[i]=='+') {i++; cnt++;}
        if(cnt>1) return 0;

       long long int num=0;
        for(int j=i;j<n;j++)
        {
           if(s[j]>=48 &&  s[j]<=57)
           {
              num=num*10+(s[j]-'0');
              if(num>INT_MAX)  break;
           }
           else
           {
            break;
           }
        }
        if(add==true)
        {
            if(num>INT_MAX) return INT_MAX;
            return (int)num;
        }
        else
        {
            long long a=-1*num;
            if(a<INT_MIN) return INT_MIN;
            return (int)a;
        }

    }
};