class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<string>st;
         int sum=0;
         for(int i=0;i<tokens.size();i++)
         {
             if(st.empty())
             {
                 st.push(tokens[i]);
                //  continue;
             }
           else if(tokens[i]=="+"  || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
             {
                  int a=stoi(st.top());
                //   cout<<a<<endl;
                  st.pop();
                  int b=stoi(st.top());
                //   cout<<b<<endl;
                  st.pop();
                  int c=0;
                  if(tokens[i]=="+")
                  {
                      c=a+b;
                    //   sum+=c;
                  }
                   if(tokens[i]=="-")
                  {
                      c=b-a;
                    //   sum+=c;
                  }
                  if(tokens[i]=="*")
                  {
                      c=a*b;
                    //   sum+=c;
                  }
                  if(tokens[i]=="/")
                  {
                      c=b/a;
                    //   sum+=c;
                  }
                  st.push(to_string(c));
                //   cout<<st.top()<<endl;
             }
             else
             {
                 st.push(tokens[i]);
             }
         }
        return stoi(st.top());
    }
};