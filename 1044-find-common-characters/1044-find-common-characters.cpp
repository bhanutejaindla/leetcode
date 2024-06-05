class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       unordered_map<char,int>mp;
       int n=words.size();
       vector<string>result;
       for(char ch='a';ch<='z';ch++)
       {
           int mini=INT_MAX;
           for(string word:words)
           {
            int count=0;
            for(char c:word)
            {
                if(c==ch)
                {
                    count++;
                }
            }
            mini=min(mini,count);
           }
           for(int i=0;i<mini;i++)
           {
            string s(1,ch);
            result.push_back(s);
           }
       }
       return result;
    }
};