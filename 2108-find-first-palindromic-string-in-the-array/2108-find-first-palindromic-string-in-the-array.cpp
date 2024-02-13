class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
        {
            string word=words[i];
            int x=0;
            int y=word.size()-1;
            bool flag=true;
            while(x<y)
            {
                if(word[x]!=word[y])
                {
                    flag=false;
                    break;
                }
                x++;y--;
            }
            if(flag==true)  return word;
        }
        return "";
    }
};