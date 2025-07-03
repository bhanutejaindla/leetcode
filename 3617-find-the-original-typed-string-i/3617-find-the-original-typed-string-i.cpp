class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char,int>mp;
        int cnt=1;
        vector<int>v;
        for(int i=1;i<word.size();i++)
        {
          if(word[i]==word[i-1])
          {
            cnt++;
          }    
          else
          {
            v.push_back(cnt);
            cnt=1;
          }
        }
        v.push_back(cnt);
        cnt=1;
        for(auto x:v)
        {
            cnt+=(x-1);
        }
        return cnt;
    }
};